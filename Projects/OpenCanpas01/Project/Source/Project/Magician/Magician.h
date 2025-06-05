// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "../Bullet/MagicianBullet.h"
#include "Magician.generated.h"

class AMagicianBullet;

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
	UFUNCTION(BlueprintPure, Category = "Attack")
	bool IsAttacking() const { return m_IsAttack; }

	UFUNCTION(BlueprintPure, Category = "Damage")
	bool IsDamage() const { return m_IsDamage; }

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// à⁄ìÆ
	void InputMove(const FInputActionValue& value);

	// çUåÇ
	void InputAttack(const FInputActionValue& value);

	// ÉWÉÉÉìÉv
	void InputJump(const FInputActionValue& value);

	// î≠éÀ
	void FireBullet();

	// çUåÇèIóπ
	void EndAttack();

	void EndDamage();

	// ìñÇΩÇËîªíË
	UFUNCTION(BlueprintCallable)
	virtual void BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp);

private:
	void SetFireDirection();
	void Damage();
	void StartHitStop();
	void EndHitStop();
	void StartInvisible();
	void EndInvisible();
	void SetVisible(bool visible);
	void FlipVisible();

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

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMagicianBullet> m_Bullet;

	UPROPERTY(EditAnywhere)
	UAnimMontage* m_AttackMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* m_DamageMontage;

	UPROPERTY(EditAnywhere)
	float m_InvisibleTime;

	bool m_IsAttack;
	bool m_IsDamage;
	bool m_IsInvisible;
	FVector2D m_InputVec;
	FVector m_LaunchVec;
	FTimerHandle m_HitstopTimerHandle;
	FTimerHandle m_InvisibleTimerHandle;
	FTimerHandle m_BlinkTimerHandle;

};
