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
		EnhancedInputComponent->BindAction(m_JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
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
	// 攻撃中は動かない
	if (m_IsAttack) return;

	// アナログスティックの入力を取得
	FVector2D inputVec = value.Get<FVector2D>();

	// アナログスティックの座標系をUEの3D座標系に変換
	FVector moveVec(inputVec.Y, inputVec.X, 0.0f);

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
		if (animInstance && !animInstance->Montage_IsPlaying(m_AttackMontage))
		{
			m_IsAttack = true;
			animInstance->Montage_Play(m_AttackMontage);
		}
	}
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
