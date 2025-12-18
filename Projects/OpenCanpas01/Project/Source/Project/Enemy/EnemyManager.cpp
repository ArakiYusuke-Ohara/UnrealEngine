// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

void UEnemyManager::RegisterEnemy(AEnemyBase* enemy)
{
    if (enemy && !m_EnemyList.Contains(enemy))
    {
        m_EnemyList.Add(enemy);
    }
}

void UEnemyManager::UnregisterEnemy(AEnemyBase* enemy)
{
    m_EnemyList.Remove(enemy);
}

void UEnemyManager::RespawnAllEnemy()
{
    for (AEnemyBase* enemy : m_EnemyList)
    {
        enemy->Respawn();
    }
}
