// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
    // レベルに配置済みの敵を収集
    TArray<AActor*> foundEnemies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyBase::StaticClass(), foundEnemies);

    for (AActor* actor : foundEnemies)
    {
        if (AEnemyBase* enemy = Cast<AEnemyBase>(actor))
        {
            RegisterEnemy(enemy);
        }
    }
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AEnemyManager* AEnemyManager::GetInstance(UWorld* world)
{
    for (TActorIterator<AEnemyManager> It(world); It; ++It)
    {
        return *It; // 最初に見つかった1体
    }
    return nullptr;
}

void AEnemyManager::RegisterEnemy(AEnemyBase* enemy)
{
    if (enemy && !m_EnemyList.Contains(enemy))
    {
        m_EnemyList.Add(enemy);
    }
}

void AEnemyManager::UnregisterEnemy(AEnemyBase* enemy)
{
    m_EnemyList.Remove(enemy);
}

void AEnemyManager::RespawnAllEnemy()
{
    for (AEnemyBase* enemy : m_EnemyList)
    {
        enemy->Respawn();
    }
}
