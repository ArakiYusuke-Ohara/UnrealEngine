// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "TitlePlayerController.generated.h"

UCLASS()
class CHARACTERPRACTICE_API ATitlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	void InputDecide(const FInputActionValue& value);

private:
	UPROPERTY(EditAnywhere)
	UInputMappingContext* m_InputMap;
	UPROPERTY(EditAnywhere)
	UInputAction* m_DecideAction;
};

