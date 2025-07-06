// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

class AEnemyBase;

UCLASS()
class PROJECT_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ƒCƒ“ƒXƒ^ƒ“ƒXæ“¾
	static AEnemyManager* GetInstance(UWorld* world);

	// “G‚Ì“o˜^‚Æ‰ğœ
	void RegisterEnemy(AEnemyBase* enemy);
	void UnregisterEnemy(AEnemyBase* enemy);

	void RespawnAllEnemy();

private:
	TArray<AEnemyBase*> m_EnemyList;
};
