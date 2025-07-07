// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalBullet.h"
#include "../Enemy/ActorEnemy.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
ANormalBullet::ANormalBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANormalBullet::BeginPlay()
{
	Super::BeginPlay();

	m_NowLife = m_Life;
}

// Called every frame
void ANormalBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 非アクティブなら処理しない
	if (!m_Active)return;

	// 常に前進
	FVector pos = GetActorLocation();
	FVector moveVec = GetActorForwardVector();
	SetActorLocation(pos + moveVec * m_Speed);

	// 寿命処理
	if (m_NowLife <= 0.0f)
	{
		// 非アクティブにする
		DisableBullet();
	}
	else
	{
		m_NowLife -= DeltaTime;
	}
}

/// <summary>
/// ヒットしたときの処理
/// BPから呼ばれる
/// </summary>
/// <param name="otherActor">衝突したActor</param>
void ANormalBullet::BeginOverlap(AActor* otherActor)
{
	// 敵にヒットしたか
	if (otherActor->IsA(AActorEnemy::StaticClass()))
	{
		// ヒットエフェクト
		if (m_HitEffect)
		{
			// エフェクトを現在の位置で発生させる
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_HitEffect, GetActorLocation());
		}

		// 非アクティブにする
		DisableBullet();
	}
}

/// <summary>
/// 引数に合わせてActorの有効/無効を設定
/// </summary>
/// <param name="active">有効/無効フラグ</param>
void ANormalBullet::Fire(FVector pos, FRotator rot)
{
	// アクティブフラグ
	m_Active = true;
	// 寿命
	m_NowLife = m_Life;
	// 座標設定
	SetActorLocation(pos);
	// 回転値設定
	SetActorRotation(rot);
	// 描画する
	SetActorHiddenInGame(false);
	// コリジョンを有効にする
	SetActorEnableCollision(true);
}

/// <summary>
/// バレットを無効にする
/// </summary>
void ANormalBullet::DisableBullet()
{
	// アクティブフラグ
	m_Active = false;
	// 描画しない
	SetActorHiddenInGame(true);
	// コリジョンを無効にする
	SetActorEnableCollision(false);
}
