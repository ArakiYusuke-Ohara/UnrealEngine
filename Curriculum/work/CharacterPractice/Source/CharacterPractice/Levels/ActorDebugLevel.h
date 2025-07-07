// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorDebugLevel.generated.h"

UCLASS()
class CHARACTERPRACTICE_API AActorDebugLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorDebugLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// çÌèúÇ≥ÇÍÇÈÇ∆Ç´Ç…åƒÇŒÇÍÇÈä÷êî
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
