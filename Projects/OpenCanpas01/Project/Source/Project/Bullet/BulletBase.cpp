// Fill out your copyright notice in the Description page of Project Settings.

#define BULLET_COOL_TIME 30.0f;

#include "BulletBase.h"
#include "NiagaraFunctionLibrary.h"
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
	// プレイヤーが撃った弾のヒット処理
	if (m_OwnerType == EBulletOwner::Player)
	{
		// 敵に当たったら消える
		if (otherActor && otherActor->IsA(AEnemyBase::StaticClass()))
		{
			AEnemyBase* enemy = Cast<AEnemyBase>(otherActor);
			if (!enemy->IsDead())
			{
				FVector pos = GetActorLocation();
				FVector otherPos = otherActor->GetActorLocation();
				FVector hitEffectPos = (pos + otherPos) / 2.0f;
				// ヒット演出
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_HitEffect, hitEffectPos);
				UAudioManager* audio = GetGameInstance()->GetSubsystem<UAudioManager>();
				audio->PlaySE(m_HitSE, pos);

				Disable();
			}
		}
	}
	// 敵が撃った弾のヒット処理
	else if (m_OwnerType == EBulletOwner::Enemy)
	{
		// プレイヤーに当たったら消える
		if (otherActor && otherActor->IsA(AMagician::StaticClass()))
		{
			AMagician* magician = Cast<AMagician>(otherActor);
			if (!magician->IsDead())
			{
				FVector otherPos = otherActor->GetActorLocation();
				FVector hitEffectPos = (GetActorLocation() + otherPos) / 2.0f;
				// ヒットエフェクト
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_HitEffect, hitEffectPos);

				Disable();
			}
		}
	}
}

void ABulletBase::PlayHitEffect()
{
}
