// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Containers/Array.h"
#include "BulletParameter.h"
#include "BulletManager.generated.h"

class ANormalBullet;

/**
 * 
 */
UCLASS()
class CHARACTERPRACTICE_API UBulletManager : public UObject
{
	GENERATED_BODY()
	
public:
	ANormalBullet* FireBullet(TSubclassOf<ANormalBullet> fireBullet, FVector pos, FRotator rot);

private:
	TArray<ANormalBullet*> m_Bullets;
};



