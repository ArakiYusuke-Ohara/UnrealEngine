// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NiagaraComponent.h"
#include "AnimNotify/EnemyAttackAnimNotify.h"
#include "EnemyBase.generated.h"

class AMagician;

UCLASS()
class PROJECT_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Respawn();

	UFUNCTION(BlueprintCallable)
	virtual void BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp);

	UFUNCTION(BlueprintCallable)
	bool IsDamage() const { return m_IsDamage; }
	UFUNCTION(BlueprintCallable)
	bool IsAttack() const { return m_IsAttack; }
	bool IsActive() const { return m_IsActive; }
	bool IsDead() const { return m_HP <= 0; }

	void BeginDamage(int value);
	void EndDamage();

	void StartHitStop();
	void EndHitStop();

	void Attack(EEnemyAttackType type);
	void EndAttack();

	void PlayMontage(UAnimMontage* montage);

	bool IsStop() const { return !m_IsActive || m_IsDamage || m_IsAttack || !m_IsStart; }


protected:
	void SetVisible(bool visible);
	void Dead();
	void Fin();

private:
	virtual void AttackA() {}
	virtual void AttackB() {}
	virtual void AttackC() {}

protected:
	bool m_IsActive;
	bool m_IsStart;
	bool m_IsAttack;
	bool m_IsDamage;

	UPROPERTY(EditAnywhere)
	int m_MaxHP;

	UPROPERTY(EditAnywhere)
	UAnimMontage* m_DamageMontage;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_DeadEffect;

	UPROPERTY(EditAnywhere)
	float m_StartDistance;

	UPROPERTY(EditAnywhere)
	float m_HitStopTime;

	int m_HP;
	AMagician* m_Player;
	FTimerHandle m_TimerHandle;
	FVector m_LaunchVec;
	FTransform m_RespawnTransform;
};
