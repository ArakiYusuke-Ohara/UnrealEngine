// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicianBullet.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/ProjectileMovementComponent.h"

void AMagicianBullet::BeginPlay()
{
	Super::BeginPlay();

	m_Movement = FindComponentByClass<UProjectileMovementComponent>();

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
	if (m_Particle)
	{
		m_ParticleComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(m_Particle, RootComponent, NAME_None, FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTargetIncludingScale, true);
	}

}

void AMagicianBullet::Disable()
{
	ABulletBase::Disable();

	if (m_ParticleComponent)
	{
		m_ParticleComponent->DestroyComponent();
		m_ParticleComponent = nullptr;
	}
	if (m_EndEffect)
	{
		// èIóπââèo
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_EndEffect, GetActorLocation());
	}
}
