// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "../Bullet/MagicianBullet.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_IsDamage = false;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	m_RespawnPos = GetActorLocation();	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase::Respawn()
{
	SetActorLocation(m_RespawnPos);
}

void AEnemyBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	// プレイヤーの弾丸に当たった
	if (otherActor->IsA(AMagicianBullet::StaticClass()))
	{
		AMagicianBullet* bullet = Cast<AMagicianBullet>(otherActor);
		StartHitStop();
		BeginDamage(bullet->GetDamage());

		// 吹っ飛ばしに使用するベクトル
		m_LaunchVec = GetActorLocation() - otherActor->GetActorLocation();
		m_LaunchVec.Normalize();
	}
}

void AEnemyBase::BeginDamage(int value)
{
	m_IsDamage = true;
	m_HP -= value;

	if (m_DamageMontage && GetMesh())
	{
		UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
		if (animInstance)
		{
			animInstance->Montage_Play(m_DamageMontage);
		}
	}
}

void AEnemyBase::EndDamage()
{
	m_IsDamage = false;
}

void AEnemyBase::StartHitStop()
{
	CustomTimeDilation = 0.05f;
	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &AEnemyBase::EndHitStop, 0.1f, false);
}

void AEnemyBase::EndHitStop()
{
	CustomTimeDilation = 1.0f;

	// HPが0以下だったら死亡
	if (m_HP <= 0)
	{
		Dead();
	}
}

void AEnemyBase::Dead()
{
	// ふっとばしベクトル
	FVector vec = m_LaunchVec * 1000.0f;

	// 地面にいて下向きに吹っ飛ぶ場合は上向きに吹っ飛ばす
	if (GetCharacterMovement()->IsMovingOnGround() && vec.Z <= 0.0f)
	{
		vec.Z = 500.0f;
	}
	LaunchCharacter(vec, true, true);

	// 一定時間後に終了、消滅
	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &AEnemyBase::Fin, 0.4f, false);
}

void AEnemyBase::Fin()
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_DeadEffect, GetActorLocation());

	Destroy();
}
