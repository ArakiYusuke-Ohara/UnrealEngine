// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../LevelBase.h"
#include "PlayLevel.generated.h"

class AMagician;

enum class PlayLevelState : uint8
{
	PLAY,
	PLAYER_DEAD,
	RETRY,
};

UCLASS()
class PROJECT_API APlayLevel : public ALevelBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayLevel();

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
	UPROPERTY(EditAnywhere)
	USoundBase* m_BGM;

	PlayLevelState m_State;
	AMagician* m_Player;
	FTimerHandle m_TimerHandle;
};
