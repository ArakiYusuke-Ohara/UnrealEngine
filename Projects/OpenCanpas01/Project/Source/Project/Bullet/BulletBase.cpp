// Fill out your copyright notice in the Description page of Project Settings.

#define BULLET_COOL_TIME 30.0f;

#include "BulletBase.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "../Enemy/EnemyBase.h"
#include "../Magician/Magician.h"
#include "../Audio/AudioManager.h"

// Sets default values
ABulletBase::ABulletBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	m_Life = 0.0f;
	m_NowLife = 0.0f;
}

// Called when the game starts or when spawned
void ABulletBase::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_Active) return;

	if (m_NowLife <= 0.0f && m_Active)
	{
		Disable();
	}
	m_NowLife -= DeltaTime;
}

void ABulletBase::Fire(FVector pos, FRotator rot)
{
	m_Active = true; 
	m_NowLife = m_Life;
	SetActorLocation(pos);
	SetActorRotation(rot);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	UAudioManager* audio = GetGameInstance()->GetSubsystem<UAudioManager>();
	audio->PlaySE(m_FireSE, pos);
}

void ABulletBase::Disable()
{
	m_Active = false;
	m_CoolTime = BULLET_COOL_TIME;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	UAudioManager* audio = GetGameInstance()->GetSubsystem<UAudioManager>();
	audio->PlaySE(m_EndSE, GetActorLocation());
}

void ABulletBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp, const FHitResult& hit)
{
}

void ABulletBase::OnHit(AActor* hitActor)
{
	// ヒットエフェクト
	if (m_HitEffect)
	{
		FVector pos = GetActorLocation();
		FVector otherPos = hitActor->GetActorLocation();
		FVector hitEffectPos = (pos + otherPos) / 2.0f;
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_HitEffect, hitEffectPos);
	}
	// ヒット音
	if (m_HitSE)
	{
		FVector pos = GetActorLocation();
		UAudioManager* audio = GetGameInstance()->GetSubsystem<UAudioManager>();
		audio->PlaySE(m_HitSE, pos);
	}

	// あたったらなくなる
	Disable();
}

void ABulletBase::PlayHitEffect()
{
}
