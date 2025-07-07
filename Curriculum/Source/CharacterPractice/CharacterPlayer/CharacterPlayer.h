// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "CharacterPlayer.generated.h"

UCLASS()
class CHARACTERPRACTICE_API ACharacterPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InputMove(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere)
	UInputMappingContext* m_InputMap;

	UPROPERTY(EditAnywhere)
	UInputAction* m_InputMove;

	UPROPERTY(EditAnywhere)
	UInputAction* m_InputJump;

	UPROPERTY(EditAnywhere)
	float m_Speed;

};
