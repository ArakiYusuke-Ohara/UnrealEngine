// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManager.h"
#include "ItemBase.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

// Sets default values
AItemManager::AItemManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemManager::BeginPlay()
{
	Super::BeginPlay();

    // レベルに配置済みのアイテムを収集
    TArray<AActor*> foundEnemies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItemBase::StaticClass(), foundEnemies);

    for (AActor* actor : foundEnemies)
    {
        if (AItemBase* item = Cast<AItemBase>(actor))
        {
            RegisterItem(item);
        }
    }
	
}

// Called every frame
void AItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AItemManager* AItemManager::GetInstance(UWorld* world)
{
    for (TActorIterator<AItemManager> It(world); It; ++It)
    {
        return *It; // 最初に見つかった1体
    }
    return nullptr;
}

void AItemManager::RegisterItem(AItemBase* item)
{
    if (item && !m_ItemList.Contains(item))
    {
        m_ItemList.Add(item);
    }
}

void AItemManager::UnregisterItem(AItemBase* item)
{
    m_ItemList.Remove(item);
}

void AItemManager::RespawnAllItem()
{
    for (AItemBase* item : m_ItemList)
    {
        item->Respawn();
    }
}
