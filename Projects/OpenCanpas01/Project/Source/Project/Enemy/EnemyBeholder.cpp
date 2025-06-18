// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBeholder.h"
#include "../Bullet/BulletManager.h"
#include "../Bullet/MagicianBullet.h"
#include "../GameInstance/MyGameInstance.h"

// Called when the game starts or when spawned
void AEnemyBeholder::BeginPlay()
{
	Super::BeginPlay();

	m_AttackTimer = m_AttackInterval;
}

// Called every frame
void AEnemyBeholder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 一定時間ごとに攻撃
	if (m_AttackTimer <= 0.0f)
	{
		StartAttack();
	}

	m_AttackTimer -= DeltaTime;
}

/// <summary>
/// 攻撃開始
/// </summary>
void AEnemyBeholder::StartAttack()
{
	m_IsAttack = true;
	PlayMontage(m_AttackMontage);
	m_AttackTimer = m_AttackInterval;
}

/// <summary>
/// 攻撃はアニメーション通知から呼ばれる
/// </summary>
void AEnemyBeholder::AttackA()
{
	if (m_Bullet)
	{
		UMyGameInstance* gameInstance = Cast<UMyGameInstance>(GetGameInstance());
		UBulletManager* bulletManager = gameInstance->GetBulletManager();
		if (bulletManager)
		{
			bulletManager->FireBullet(m_Bullet, GetActorLocation(), GetActorRotation());
		}
	}
}
