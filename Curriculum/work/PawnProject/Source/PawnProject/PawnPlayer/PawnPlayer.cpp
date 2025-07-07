// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
APawnPlayer::APawnPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnPlayer::BeginPlay()
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
void APawnPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (enhancedInput)
    {
        // インプットアクションと対応する移動関数をバインド
        enhancedInput->BindAction(m_InputUp, ETriggerEvent::Triggered, this, &APawnPlayer::MoveUp);
        enhancedInput->BindAction(m_InputDown, ETriggerEvent::Triggered, this, &APawnPlayer::MoveDown);
        enhancedInput->BindAction(m_InputLeft, ETriggerEvent::Triggered, this, &APawnPlayer::MoveLeft);
        enhancedInput->BindAction(m_InputRight, ETriggerEvent::Triggered, this, &APawnPlayer::MoveRight);
    }
}

void APawnPlayer::MoveUp(const FInputActionValue& Value)
{
    // 入力加減を取得する キーボードなら0か1
    float inputValue = Value.Get<float>();

    // 移動ベクトルを作成
    FVector move(0.0f, 0.0f, inputValue * m_Speed);

    // FloatingPawnComponentはAddMovementInputを使って移動する
    AddMovementInput(move);
}

void APawnPlayer::MoveDown(const FInputActionValue& Value)
{
    // 入力加減を取得する キーボードなら0か1
    float inputValue = Value.Get<float>();

    // 移動ベクトルを作成
    FVector move(0.0f, 0.0f, -(inputValue * m_Speed));

    // FloatingPawnComponentはAddMovementInputを使って移動する
    AddMovementInput(move);
}

void APawnPlayer::MoveLeft(const FInputActionValue& Value)
{
    // 入力加減を取得する キーボードなら0か1
    float inputValue = Value.Get<float>();

    // 移動ベクトルを作成
    FVector move(0.0f, -(inputValue * m_Speed), 0.0f);

    // FloatingPawnComponentはAddMovementInputを使って移動する
    AddMovementInput(move);
}

void APawnPlayer::MoveRight(const FInputActionValue& Value)
{
    // 入力加減を取得する キーボードなら0か1
    float inputValue = Value.Get<float>();

    // 移動ベクトルを作成
    FVector move(0.0f, inputValue * m_Speed, 0.0f);

    // FloatingPawnComponentはAddMovementInputを使って移動する
    AddMovementInput(move);
}
