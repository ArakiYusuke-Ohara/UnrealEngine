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

	m_RespawnTransform = GetActorTransform();
	m_IsActive = true;
	m_HP = m_MaxHP;
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// リスポーン処理
/// </summary>
void AEnemyBase::Respawn()
{
	// HP再設定
	m_HP = m_MaxHP;

	// アクティブと表示
	m_IsActive = true;
	SetVisible(true);

	SetActorTransform(m_RespawnTransform);
}

/// <summary>
/// オーバーラップ衝突処理
/// </summary>
/// <param name="otherActor"></param>
/// <param name="otherComp"></param>
void AEnemyBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	if (IsDead())return;

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

/// <summary>
/// ダメージ開始
/// </summary>
/// <param name="value">ダメージ量</param>
void AEnemyBase::BeginDamage(int value)
{
	m_IsDamage = true;
	m_HP -= value;

	// アニメーションをモンタージュから再生
	PlayMontage(m_DamageMontage);
}

/// <summary>
/// ダメージ終了
/// </summary>
void AEnemyBase::EndDamage()
{
	m_IsDamage = false;
}

/// <summary>
/// ヒットストップ開始
/// </summary>
void AEnemyBase::StartHitStop()
{
	CustomTimeDilation = 0.05f;
	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &AEnemyBase::EndHitStop, 0.1f, false);
}

/// <summary>
/// ヒットストップ終了
/// </summary>
void AEnemyBase::EndHitStop()
{
	CustomTimeDilation = 1.0f;

	// HPが0以下だったら死亡
	if (m_HP <= 0)
	{
		Dead();
	}
}

/// <summary>
/// 攻撃開始
/// </summary>
/// <param name="type">攻撃タイプ</param>
void AEnemyBase::Attack(EEnemyAttackType type)
{
	switch (type)
	{
		case EEnemyAttackType::AttackA: AttackA(); break;
		case EEnemyAttackType::AttackB: AttackB(); break;
		case EEnemyAttackType::AttackC: AttackC(); break;
	}
}

/// <summary>
/// 攻撃終了
/// </summary>
void AEnemyBase::EndAttack()
{
	m_IsAttack = false;
}

/// <summary>
/// アニメーションモンタージュを再生する
/// </summary>
/// <param name="montage">再生するモンタージュ</param>
void AEnemyBase::PlayMontage(UAnimMontage* montage)
{
	if (montage && GetMesh())
	{
		UAnimInstance* animInstance = GetMesh()->GetAnimInstance();
		if (animInstance)
		{
			animInstance->Montage_Play(montage);
		}
	}
}

/// <summary>
/// 表示/非表示設定
/// </summary>
/// <param name="visible"></param>
void AEnemyBase::SetVisible(bool visible)
{
	USkeletalMeshComponent* mesh = GetMesh();
	if (mesh)
	{
		mesh->SetVisibility(visible, true);
	}
}

/// <summary>
/// 死亡処理
/// </summary>
void AEnemyBase::Dead()
{
	// ふっとばしベクトル
	FVector vec = m_LaunchVec * 1000.0f;

	// 地面にいて下向きに吹っ飛ぶ場合は上向きに吹っ飛ばす
	if (GetCharacterMovement()->IsMovingOnGround() && vec.Z <= 0.0f)
	{
		vec.Z = 500.0f;
	}

	// 吹っ飛ばすにはCharacterMovementが必要なので確実に復活させる
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);

	// 吹っ飛ばす
	LaunchCharacter(vec, true, true);

	// 一定時間後に終了、消滅
	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &AEnemyBase::Fin, 0.4f, false);
}

/// <summary>
/// 終了処理
/// </summary>
void AEnemyBase::Fin()
{
	// 死亡エフェクト
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_DeadEffect, GetActorLocation());

	// 非アクティブと非表示
	m_IsActive = false;
	SetVisible(false);
}
