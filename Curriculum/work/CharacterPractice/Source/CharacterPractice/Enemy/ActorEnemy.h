// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorEnemy.generated.h"

UCLASS(Blueprintable)
class CHARACTERPRACTICE_API AActorEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// BP‚©‚çŒÄ‚Î‚ê‚é’eŠÛ‚ªƒqƒbƒg‚µ‚½‚Æ‚«‚Ìˆ—
	UFUNCTION(BlueprintCallable)
	void BeginOverlap(AActor* otherActor);

private:

	UPROPERTY(EditAnywhere)
	int m_HP;
};
