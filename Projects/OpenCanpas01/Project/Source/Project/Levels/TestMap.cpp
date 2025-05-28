// Fill out your copyright notice in the Description page of Project Settings.


#include "TestMap.h"
#include "../GameInstance/MyGameInstance.h"

// Sets default values
ATestMap::ATestMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestMap::BeginPlay()
{
	Super::BeginPlay();
	
	UMyGameInstance* gameInstance = Cast<UMyGameInstance>(GetGameInstance());
	gameInstance->CreateBulletManager();
}

// Called every frame
void ATestMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestMap::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UMyGameInstance* gameInstance = Cast<UMyGameInstance>(GetGameInstance());

	if (gameInstance)
	{
		gameInstance->DeleteBulletManager();
	}
}
