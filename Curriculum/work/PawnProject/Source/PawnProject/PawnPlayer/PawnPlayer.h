// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "PawnPlayer.generated.h"

UCLASS()
class PAWNPROJECT_API APawnPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveUp(const FInputActionValue& Value);
	void MoveDown(const FInputActionValue& Value);
	void MoveLeft(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);

private:

	UPROPERTY(EditAnywhere)
	UInputMappingContext* m_InputMap;

	UPROPERTY(EditAnywhere)
	UInputAction* m_InputUp;

	UPROPERTY(EditAnywhere)
	UInputAction* m_InputDown;

	UPROPERTY(EditAnywhere)
	UInputAction* m_InputLeft;

	UPROPERTY(EditAnywhere)
	UInputAction* m_InputRight;

	UPROPERTY(EditAnywhere)
	float m_Speed;

};
