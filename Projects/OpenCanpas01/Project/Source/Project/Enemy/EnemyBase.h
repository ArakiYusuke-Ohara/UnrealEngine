// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NiagaraComponent.h"
#include "EnemyBase.generated.h"

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

	void BeginDamage(int value);
	void EndDamage();

	void StartHitStop();
	void EndHitStop();

protected:
	void Dead();
	void Fin();

protected:
	bool m_IsDamage;

	UPROPERTY(EditAnywhere)
	int m_HP;

	UPROPERTY(EditAnywhere)
	UAnimMontage* m_DamageMontage;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_DeadEffect;

	FTimerHandle m_TimerHandle;

	FVector m_LaunchVec;
	FVector m_RespawnPos;
};
