// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicianBullet.h"
#include "NiagaraComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

void AMagicianBullet::BeginPlay()
{
	Super::BeginPlay();

	m_Movement = FindComponentByClass<UProjectileMovementComponent>();
	m_Niagara = FindComponentByClass<UNiagaraComponent>();
}

void AMagicianBullet::Fire(FVector pos, FRotator rot)
{
	ABulletBase::Fire(pos, rot);

	if (m_Movement)
	{
		FVector ForwardDir = GetActorForwardVector();
		float Speed = m_Movement->InitialSpeed;
		m_Movement->Velocity = ForwardDir * Speed;
	}
	if (m_Niagara)
	{
		m_Niagara->Activate();
	}
}

void AMagicianBullet::Disable()
{
	ABulletBase::Disable();

	if (m_Niagara)
	{
		m_Niagara->DeactivateImmediate();
	}
}
