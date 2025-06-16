// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemCoin.h"

// Called every frame
void AItemCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, m_RotationSpeed * DeltaTime, 0.0f));
}

void AItemCoin::Taked()
{
	Super::Taked();
}
