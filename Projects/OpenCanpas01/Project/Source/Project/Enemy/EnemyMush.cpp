// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMush.h"

// Called every frame
void AEnemyMush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_IsDamage)
	{
		// Œü‚¢‚Ä‚¢‚é•ûŒü‚É‚Ü‚Á‚·‚®i‚Ş
		AddMovementInput(GetActorForwardVector(), m_Speed);
	}
}
