// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "Magician.generated.h"

UCLASS()
class PROJECT_API AMagician : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMagician();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// à⁄ìÆ
	void InputMove(const FInputActionValue& value);

	// çUåÇ
	void InputAttack(const FInputActionValue& value);

private:

	UPROPERTY(EditAnywhere)
	UInputMappingContext* m_InputMap;

	UPROPERTY(EditAnywhere)
	UInputAction* m_MoveAction;

	UPROPERTY(EditAnywhere)
	UInputAction* m_JumpAction;

	UPROPERTY(EditAnywhere)
	UInputAction* m_FireBulletAction;

	UPROPERTY(EditAnywhere)
	float m_MoveSpeed;

};
