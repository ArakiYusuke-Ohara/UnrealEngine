// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

class UBulletManager;

/**
 * 
 */
UCLASS()
class PROJECT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

public:
	void CreateBulletManager();
	UBulletManager* GetBulletManager() const { return m_BulletManager; }
	void DeleteBulletManager();

private:
	UBulletManager* m_BulletManager;
};
