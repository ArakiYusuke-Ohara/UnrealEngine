// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioManager.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

void UAudioManager::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);
}

UWorld* UAudioManager::GetWorldSafe() const
{
	if (GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}

	return nullptr;
}


void UAudioManager::PlayBGM(USoundBase* sound, float fadeInTime)
{
	UWorld* world = GetWorldSafe();
	if (!world || !sound) return;

	// 既に何か鳴ってたらフェードアウト
	if (m_BGMComponent)
	{
		m_BGMComponent->FadeOut(0.5f, 0.0f);
	}

	// BGM用オブジェクトをスポーンして再生
	m_BGMComponent = UGameplayStatics::SpawnSound2D(world, sound);
	if (m_BGMComponent)
	{
		m_BGMComponent->FadeIn(fadeInTime, 1.0f);
	}
}

void UAudioManager::StopBGM(float fadeOutTime)
{
	// フェードアウト
	if (m_BGMComponent)
	{
		m_BGMComponent->FadeOut(fadeOutTime, 0.0f);
		m_BGMComponent = nullptr;
	}
}

void UAudioManager::PlaySE(USoundBase* sound, FVector location)
{
	UWorld* world = GetWorldSafe();
	if (!world || !sound) return;

	// SE再生
	UGameplayStatics::PlaySoundAtLocation(world, sound, location);
}

