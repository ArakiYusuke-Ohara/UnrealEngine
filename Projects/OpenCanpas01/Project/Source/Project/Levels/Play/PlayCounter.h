// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PlayCounter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UPlayCounter : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	void AddCoin(int num = 1) { m_Coin += num; }
	void AddKillEnemy(int num = 1) { m_KillEnemy += num; }

	int GetCoin() const { return m_Coin; }
	int GetKillEnemy() const { return m_KillEnemy; }

	void ResetCounter();

	bool IsStageComplete();

private:
	uint16 m_Coin = 0;
	uint16 m_KillEnemy = 0;
};
