// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ACharacterPlayer::ACharacterPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
    // 入力マッピングを設定するためPlayerControllerを取得
    APlayerController* playerController = GetWorld()->GetFirstPlayerController();
    if (playerController)
    {
        // LocalPlayerを取得
        ULocalPlayer* LocalPlayer = playerController->GetLocalPlayer();
        if (LocalPlayer)
        {
            // 入力マッピングを管理するシステムを取得
            UEnhancedInputLocalPlayerSubsystem* inputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
            if (inputSubsystem)
            {
                // BPで設定した入力マッピングをシステムに追加
                inputSubsystem->AddMappingContext(m_InputMap, 0);
            }
        }
    }

}

// Called every frame
void ACharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (enhancedInput)
    {
        // インプットアクションと対応する移動関数をバインド
        enhancedInput->BindAction(m_InputMove, ETriggerEvent::Triggered, this, &ACharacterPlayer::InputMove);
        // ジャンプはACharacterに処理がある
        enhancedInput->BindAction(m_InputJump, ETriggerEvent::Started, this, &ACharacter::Jump);
        enhancedInput->BindAction(m_InputJump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
    }
}

void ACharacterPlayer::InputMove(const FInputActionValue& Value)
{
    // アナログスティックの入力をベクトルで取得
    FVector2D moveVec2D = Value.Get<FVector2D>();

    // アナログスティックのXY軸とUEのXY軸は違うので変換
    FVector moveVec(moveVec2D.Y, moveVec2D.X, 0.0f);

    // 移動
    AddMovementInput(moveVec, m_Speed);
}

