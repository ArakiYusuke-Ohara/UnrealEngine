// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "EnemySwarm.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AEnemySwarm : public AEnemyBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Respawn() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
