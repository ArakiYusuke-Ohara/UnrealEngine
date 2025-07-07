// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorDebugLevel.h"
#include "../MainGameInstance/MainGameInstance.h"

// Sets default values
AActorDebugLevel::AActorDebugLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorDebugLevel::BeginPlay()
{
	Super::BeginPlay();

	// GameInstanceを取得
	UMainGameInstance* gameInstance = Cast<UMainGameInstance>(GetGameInstance());

	// 必要なマネージャークラスを生成する
	gameInstance->CreateBulletManager();
}

// 削除されるときに呼ばれる
void AActorDebugLevel::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay (EndPlayReason);

	// GameInstanceを取得
	UMainGameInstance* gameInstance = Cast<UMainGameInstance>(GetGameInstance());

	if (gameInstance)
	{
		// 不要になるマネージャークラスは削除
		gameInstance->DeleteBulletManager();
	}
}

// Called every frame
void AActorDebugLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

