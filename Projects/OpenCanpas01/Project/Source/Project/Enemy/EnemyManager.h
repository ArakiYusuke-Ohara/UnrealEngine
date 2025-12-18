// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EnemyManager.generated.h"

class AEnemyBase;

UCLASS()
class PROJECT_API UEnemyManager : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	// ìGÇÃìoò^Ç∆âèú
	void RegisterEnemy(AEnemyBase* enemy);
	void UnregisterEnemy(AEnemyBase* enemy);

	void RespawnAllEnemy();

private:
	TArray<AEnemyBase*> m_EnemyList;
};
