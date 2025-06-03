// Fill out your copyright notice in the Description page of Project Settings.


#include "Magician.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "../Bullet/BulletManager.h"
#include "../GameInstance/MyGameInstance.h"

// Sets default values
AMagician::AMagician()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Bullet = nullptr;
	m_IsAttack = false;

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

	// 攻撃中は動かない
	if (m_IsAttack) return;


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
	// 攻撃モンタージュを再生する
	// 弾の発射はモンタージュから通知される
	if (m_AttackMontage && GetMesh())
	{
		UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
		if (animInstance && !m_IsAttack)
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
	if (m_IsAttack) return;

	Jump();
}

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

void AMagician::EndAttack()
{
	m_IsAttack = false;
}

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