// Fill out your copyright notice in the Description page of Project Settings.


#include "Magician.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Bullet/BulletManager.h"
#include "../GameInstance/MyGameInstance.h"
#include "../Enemy/EnemyBase.h"

// Sets default values
AMagician::AMagician()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Bullet = nullptr;
	m_IsAttack = false;
	m_IsDamage = false;
	m_IsInvincible = false;
	m_InvisibleTime = 0.0f;
}

// Called when the game starts or when spawned
void AMagician::BeginPlay()
{
	Super::BeginPlay();
	
	// インプットマップを設定
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(m_InputMap, 0);
		}
	}

	bUseControllerRotationYaw = false;
	m_IsAttack = false;
	m_RespawnPos = GetActorLocation();
	m_RespawnRot = GetActorRotation();
	m_HP = m_MaxHP;
}

// Called every frame
void AMagician::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMagician::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 入力アクションを設定
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// ジャンプ
		EnhancedInputComponent->BindAction(m_JumpAction, ETriggerEvent::Started, this, &AMagician::InputJump);
		EnhancedInputComponent->BindAction(m_JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// 移動
		EnhancedInputComponent->BindAction(m_MoveAction, ETriggerEvent::Triggered, this, &AMagician::InputMove);

		// 弾丸発射
		EnhancedInputComponent->BindAction(m_FireBulletAction, ETriggerEvent::Started, this, &AMagician::InputAttack);
	}

}

/// <summary>
/// 入力移動処理
/// </summary>
/// <param name="value">入力値(FVector2D)</param>
void AMagician::InputMove(const FInputActionValue& value)
{
	// アナログスティックの入力を取得
	m_InputVec = value.Get<FVector2D>();

	if (!IsControll()) return;

	// アナログスティックの座標系をUEの3D座標系に変換
	FVector moveVec(0.0f, m_InputVec.X, 0.0f);

	// 移動
	AddMovementInput(moveVec, m_MoveSpeed);
}

/// <summary>
/// 攻撃
/// </summary>
/// <param name="value">入力値(bool)</param>
void AMagician::InputAttack(const FInputActionValue& value)
{
	if (!IsControll()) return;

	// 攻撃モンタージュを再生する
	// 弾の発射はモンタージュから通知される
	if (m_AttackMontage && GetMesh())
	{
		UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
		if (animInstance)
		{
			SetFireDirection();

			m_IsAttack = true;
			animInstance->Montage_Play(m_AttackMontage);
		}
	}
}

/// <summary>
/// ジャンプ
/// </summary>
/// <param name="value">入力値(bool)</param>
void AMagician::InputJump(const FInputActionValue& value)
{
	if (!IsControll()) return;

	Jump();
}

/// <summary>
/// 弾丸を発射する
/// AnimNotifyから呼び出される
/// </summary>
void AMagician::FireBullet()
{
	if (m_Bullet)
	{
		UMyGameInstance* gameInstance = Cast<UMyGameInstance>(GetGameInstance());
		UBulletManager* bulletManager = gameInstance->GetBulletManager();
		if (bulletManager)
		{
			bulletManager->FireBullet(m_Bullet, GetActorLocation(), GetActorRotation());
		}
	}
}

/// <summary>
/// 攻撃終了
/// </summary>
void AMagician::EndAttack()
{
	m_IsAttack = false;
}

/// <summary>
/// ダメージ終了
/// </summary>
void AMagician::EndDamage()
{
	m_IsDamage = false;
	GetWorld()->GetTimerManager().SetTimer(m_BlinkTimerHandle, this, &AMagician::FlipVisible, 0.1f, true);
}

/// <summary>
/// 左右どちらに発射するかを決める
/// </summary>
void AMagician::SetFireDirection()
{
	FRotator result = {};
	FRotator playerRot = GetActorRotation();

	// 必ず真横を向かせる

	// 入力があれば入力を優先
	if (m_InputVec.X > 0.0f)
	{
		result = FRotator(0.0f, 90.0f, 0.0f);
	}
	else if (m_InputVec.X < 0.0f)
	{
		result = FRotator(0.0f, -90.0f, 0.0f);
	}
	// 入力がなければ現在の向きから判定
	else if (playerRot.Yaw > 0.0f)
	{
		result = FRotator(0.0f, 90.0f, 0.0f);
	}
	else if (playerRot.Yaw < 0.0f)
	{
		result = FRotator(0.0f, -90.0f, 0.0f);
	}

	// 真横の向きを設定
	SetActorRotation(result);
}

/// <summary>
/// ダメージ処理
/// </summary>
void AMagician::Damage()
{
	// ダメージエフェクト
	if (m_DamageEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_DamageEffect, m_DamagePos);
	}

	// HP減少
	m_HP--;

	// 死亡判定
	if (m_HP <= 0)
	{
		m_IsDead = true;
		// 一定時間後に死亡終了処理
		GetWorld()->GetTimerManager().SetTimer(m_DeadTimerHandle, this, &AMagician::EndDead, 2.0f, false);
	}
	// 死亡してない場合
	else
	{
		m_IsDamage = true;

		// ダメージモンタージュを再生する
		if (m_DamageMontage && GetMesh())
		{
			UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
			if (animInstance)
			{
				animInstance->Montage_Play(m_DamageMontage);
			}
		}

		// 無敵開始
		StartInvisible();
	}
}

/// <summary>
/// ヒットストップ開始
/// </summary>
void AMagician::StartHitStop()
{
	CustomTimeDilation = 0.05f;
	GetWorld()->GetTimerManager().SetTimer(m_HitstopTimerHandle, this, &AMagician::EndHitStop, 0.1f, false);
}

/// <summary>
/// ヒットストップ終了
/// </summary>
void AMagician::EndHitStop()
{
	CustomTimeDilation = 1.0f;
	LaunchCharacter(m_LaunchVec * 600.0f, true, true);
}

/// <summary>
/// 無敵開始
/// </summary>
void AMagician::StartInvisible()
{
	m_IsInvincible = true;
	GetWorld()->GetTimerManager().SetTimer(m_InvisibleTimerHandle, this, &AMagician::EndInvisible, m_InvisibleTime, false);
}

/// <summary>
/// 無敵終了
/// </summary>
void AMagician::EndInvisible()
{
	m_IsInvincible = false;
	GetWorld()->GetTimerManager().ClearTimer(m_BlinkTimerHandle);
	SetVisible(true);
}

/// <summary>
/// 表示/非表示設定
/// </summary>
/// <param name="visible"></param>
void AMagician::SetVisible(bool visible)
{
	USkeletalMeshComponent* mesh = GetMesh();
	if (mesh)
	{
		mesh->SetVisibility(visible, true);
	}
}

/// <summary>
/// 表示/非表示反転
/// </summary>
void AMagician::FlipVisible()
{
	USkeletalMeshComponent* mesh = GetMesh();
	if (mesh)
	{
		bool bVisible = mesh->IsVisible();
		mesh->SetVisibility(!bVisible, true);
	}
}

/// <summary>
/// 死亡終了処理
/// </summary>
void AMagician::EndDead()
{
	// 非表示
	SetVisible(false);

	// 死亡エフェクト
	if (m_DeadEffect)
	{
		if (GetMesh()->DoesSocketExist(FName("spine_02")))
		{
			FVector pos = GetMesh()->GetSocketLocation(FName("spine_02"));
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_DeadEffect, pos);
		}
	}
}

/// <summary>
/// リスポーン処理
/// </summary>
void AMagician::Respawn()
{
	// 死亡は解除する
	m_IsDead = false;

	// HP再設定
	m_HP = m_MaxHP;

	// 表示
	SetVisible(true);
	// リスポーン位置にワープ
	TeleportTo(m_RespawnPos, m_RespawnRot, false, true);
	// 無敵にしとく
	StartInvisible();
	// 無敵点滅
	GetWorld()->GetTimerManager().SetTimer(m_BlinkTimerHandle, this, &AMagician::FlipVisible, 0.1f, true);
}

bool AMagician::IsControll()
{
	if (m_IsAttack) return false;
	if (m_IsDamage) return false;
	if (m_IsDead) return false;

	return true;
}

/// <summary>
/// オーバーラップ処理
/// </summary>
/// <param name="otherActor">当たったアクター</param>
/// <param name="otherComp">当たったコンポーネント</param>
void AMagician::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	// 死んでいたら何もしない
	if (m_IsDead) return;

	// 敵に当たった
	if (otherActor->IsA(AEnemyBase::StaticClass()))
	{
		if (!m_IsInvincible)
		{
			// 吹っ飛びベクトルを計算
			m_LaunchVec = FVector::ZeroVector;
			m_LaunchVec.Y = GetActorLocation().Y - otherActor->GetActorLocation().Y;
			m_LaunchVec.Z = FMath::Abs(m_LaunchVec.Y);
			m_LaunchVec.Normalize();

			otherComp->GetClosestPointOnCollision(GetActorLocation(), m_DamagePos);

			StartHitStop();
			Damage();
		}
	}
}
