// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemManager.h"
#include "ItemBase.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "ItemCoin.h"

void UItemManager::RegisterItem(AItemBase* item)
{
    if (item && !m_ItemList.Contains(item))
    {
        m_ItemList.Add(item);
    }
    // ƒRƒCƒ“‚Ì”‚Í”‚¦‚é
    if (item->IsA(AItemCoin::StaticClass()))
    {
        m_CoinMax++;
    }
}

void UItemManager::UnregisterItem(AItemBase* item)
{
    m_ItemList.Remove(item);
}

void UItemManager::RespawnAllItem()
{
    for (AItemBase* item : m_ItemList)
    {
        item->Respawn();
    }
}
