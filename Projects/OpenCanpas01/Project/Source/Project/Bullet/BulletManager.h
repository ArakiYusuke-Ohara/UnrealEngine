// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Containers/Array.h"
#include "BulletManager.generated.h"

class ABulletBase;

/**
 * 
 */
UCLASS()
class PROJECT_API UBulletManager : public UObject
{
	GENERATED_BODY()

public:
	UBulletManager();
	~UBulletManager();

public:
	ABulletBase* FireBullet(TSubclassOf<ABulletBase> fireBullet, FVector pos, FRotator rot);

private:
	TArray<ABulletBase*> m_Bullets;
};
