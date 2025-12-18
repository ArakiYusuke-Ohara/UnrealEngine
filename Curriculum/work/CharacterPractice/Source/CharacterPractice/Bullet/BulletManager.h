// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Subsystems/WorldSubsystem.h"
#include "BulletManager.generated.h"

class ANormalBullet;

/**
 * 
 */
UCLASS()
class CHARACTERPRACTICE_API UBulletManager : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	ANormalBullet* FireBullet(TSubclassOf<ANormalBullet> fireBullet, FVector pos, FRotator rot);

private:
	TArray<TWeakObjectPtr<ANormalBullet>> m_Bullets;
};



