// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorTitleLevel.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AActorTitleLevel::AActorTitleLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorTitleLevel::BeginPlay()
{
	Super::BeginPlay();
	
	// BPで設定したウィジェットを表示する
	if (m_UIWidget)
	{
		m_UIWidget->AddToViewport();
	}
}

// Called every frame
void AActorTitleLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

