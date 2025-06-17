// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "EnemyBeholder.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AEnemyBeholder : public AEnemyBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void AttackA() final;

private:
	void StartAttack();

protected:
	UPROPERTY(EditAnywhere)
	float m_AttackInterval;

	UPROPERTY(EditAnywhere)
	UAnimMontage* m_AttackMontage;

	float m_AttackTimer;
};
