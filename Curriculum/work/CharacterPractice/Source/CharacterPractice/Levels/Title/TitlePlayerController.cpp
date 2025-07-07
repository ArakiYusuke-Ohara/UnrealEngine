// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"

void ATitlePlayerController::SetupInputComponent()
{
	// インプットマップを設定
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	if (controller)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = 
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(m_InputMap, 0);
		}
	}

	// 入力アクションを設定
	UEnhancedInputComponent* EnhancedInput = NewObject<UEnhancedInputComponent>(this);
	if (EnhancedInput)
	{
		EnhancedInput->BindAction(m_DecideAction, ETriggerEvent::Triggered, this, &ATitlePlayerController::InputDecide);
		InputComponent = EnhancedInput;
	}
}

void ATitlePlayerController::InputDecide(const FInputActionValue& value)
{
	// デバッグレベルへ遷移
	UGameplayStatics::OpenLevel(this, FName(TEXT("DebugLevel")));
}


