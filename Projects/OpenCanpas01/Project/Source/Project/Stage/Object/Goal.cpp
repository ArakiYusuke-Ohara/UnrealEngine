// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "../../Magician/Magician.h"
#include"Kismet/GameplayStatics.h"
// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// オーバーラップ衝突処理
/// </summary>
/// <param name="otherActor"></param>
/// <param name="otherComp"></param>
void AGoal::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	// プレイヤーが当たったらゴール
	if (otherActor->IsA(AMagician::StaticClass()))
	{

	}
}
