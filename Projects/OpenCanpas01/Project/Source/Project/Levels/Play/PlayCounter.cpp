// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayCounter.h"
#include "../../Enemy/EnemyManager.h"
#include "../../Item/ItemManager.h"

void UPlayCounter::ResetCounter()
{
	m_Coin = 0;
	m_KillEnemy = 0;
}

bool UPlayCounter::IsStageComplete()
{
	UItemManager* itemManager = GetWorld()->GetSubsystem<UItemManager>();
	UEnemyManager* enemyManager = GetWorld()->GetSubsystem<UEnemyManager>();

	if (m_Coin >= itemManager->GetCoinMax() && m_KillEnemy >= enemyManager->GetEnemyMax())
	{
		return true;
	}

	return false;
}
