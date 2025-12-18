// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ItemManager.generated.h"

class AItemBase;

UCLASS()
class PROJECT_API UItemManager : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:	
	// ìGÇÃìoò^Ç∆âèú
	void RegisterItem(AItemBase* item);
	void UnregisterItem(AItemBase* item);

	void RespawnAllItem();

private:
	TArray<AItemBase*> m_ItemList;

};
