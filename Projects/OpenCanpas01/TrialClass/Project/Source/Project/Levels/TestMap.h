// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMap.generated.h"

class AMagician;

enum class PlayMapState : uint8
{
	PLAY,
	PLAYER_DEAD,
	FADE_OUT,
};

UCLASS()
class PROJECT_API ATestMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void FadeOut();
	void Restart();

private:
	PlayMapState m_State;
	AMagician* m_Player;
	FTimerHandle m_TimerHandle;
};
