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
	void RegisterCoin(int num = 1) { m_CoinMax += num; }

	void AddKill(int num = 1) { m_Kill += num; }
	void RegisterEnemy(int num = 1) { m_KillMax += num; }

	int GetCoin() const { return m_Coin; }
	int GetCoinMax() const { return m_CoinMax; }
	int GetKill() const { return m_Kill; }
	int GetKillMax() const { return m_KillMax; }

	void ResetAddCount();

private:
	uint16 m_Coin = 0;
	uint16 m_CoinMax = 0;
	uint16 m_Kill = 0;
	uint16 m_KillMax = 0;
};
