// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

class UBulletManager;

/**
 * 
 */
UCLASS()
class CHARACTERPRACTICE_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	void CreateBulletManager();
	UBulletManager* GetBulletManager() const { return m_BulletManager; }
	void DeleteBulletManager();

private:
	UBulletManager* m_BulletManager;

};


