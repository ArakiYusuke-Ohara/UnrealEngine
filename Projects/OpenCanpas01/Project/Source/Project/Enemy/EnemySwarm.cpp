// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySwarm.h"
#include "GameFramework/CharacterMovementComponent.h"

// Called when the game starts or when spawned
void AEnemySwarm::BeginPlay()
{
	Super::BeginPlay();

	m_StartPos = GetActorLocation();
}

void AEnemySwarm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_IsDamage) return;

	FVector pos = m_StartPos;

	if (m_IsYMove)
	{
		pos.Y = m_StartPos.Y + FMath::Cos(m_Angle) * m_Radius;
	}
	if (m_IsZMove)
	{
		pos.Z = m_StartPos.Z + FMath::Sin(m_Angle) * m_Radius;
	}

	SetActorLocation(pos);

	m_Angle += 2.0f * PI * (DeltaTime / m_Time);
	m_Angle = FMath::Wrap(m_Angle, 0.0f, 2.0f * PI);
}