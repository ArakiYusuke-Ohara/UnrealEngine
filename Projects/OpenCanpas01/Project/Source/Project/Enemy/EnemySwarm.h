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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	bool m_IsYMove;

	UPROPERTY(EditAnywhere)
	bool m_IsZMove;

	UPROPERTY(EditAnywhere)
	float m_Radius;

	UPROPERTY(EditAnywhere)
	float m_Time;

	float m_Angle;
	FVector m_StartPos;
};
