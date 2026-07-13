// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Sound/SoundBase.h"
#include "AudioManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UAudioManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& collection);
	UWorld* GetWorldSafe() const;

	void PlayBGM(USoundBase* sound, float fadeInTime = 1.0f);
	void StopBGM(float fadeOutTime = 1.0f);

	void PlaySE(USoundBase* sound, FVector location);

private:
	UAudioComponent* m_BGMComponent;
};
