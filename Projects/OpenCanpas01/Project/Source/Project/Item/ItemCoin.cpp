// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemCoin.h"
#include "../Levels/Play/PlayCounter.h"

// Called when the game starts or when spawned
void AItemCoin::BeginPlay()
{
	Super::BeginPlay();

	// カウンターにコイン登録
	GetWorld()->GetSubsystem<UPlayCounter>()->RegisterCoin();
}

// Called every frame
void AItemCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_IsActive) return;

	AddActorLocalRotation(FRotator(0.0f, m_RotationSpeed * DeltaTime, 0.0f));
}

void AItemCoin::Taked()
{
	Super::Taked();

	// コイン獲得カウント
	GetWorld()->GetSubsystem<UPlayCounter>()->AddCoin();
}
