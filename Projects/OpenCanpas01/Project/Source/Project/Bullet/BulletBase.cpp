// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "../Enemy/EnemyBase.h"
#include "NiagaraFunctionLibrary.h"

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
}

void ABulletBase::Disable()
{
	m_Active = false;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ABulletBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp, const FHitResult& hit)
{
	// WorldStaticに当たったら消える
	if (otherComp && otherComp->GetCollisionObjectType() == ECC_WorldStatic)
	{
		Disable();
	}
	// 敵に当たったら消える
	if (otherActor && otherActor->IsA(AEnemyBase::StaticClass()))
	{
		FVector otherPos = otherActor->GetActorLocation();
		FVector hitEffectPos = (GetActorLocation() + otherPos) / 2.0f;
		// ヒットエフェクト
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_HitEffect, hitEffectPos);

		Disable();
	}
}

void ABulletBase::PlayHitEffect()
{
}
