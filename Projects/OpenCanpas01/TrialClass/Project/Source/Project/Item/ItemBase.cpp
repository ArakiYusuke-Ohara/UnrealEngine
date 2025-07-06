// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "../Magician/Magician.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
	m_RespawnTransform = GetActorTransform();
	m_IsActive = true;
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// アイテムのプログラム
/// 何かが重なったときに処理される
/// </summary>
/// <param name="otherActor">重なってきたもの</param>
/// <param name="otherComp">重なってきたものが持つコンポーネント</param>
void AItemBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	if (!m_IsActive)return;

	if (otherActor->IsA(AMagician::StaticClass()))
	{ // プレイヤーが重なった
		
		// ①アイテムが取られた！！ 

	}
}

void AItemBase::Respawn()
{
	SetActorTransform(m_RespawnTransform);

	// アクティブと表示
	m_IsActive = true;
	SetVisible(true);
}

/// <summary>
/// アイテムが取られた
/// </summary>
void AItemBase::Taked()
{
	// ゲットエフェクト
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_GetEffect, GetActorLocation());

	// 取られたので無効化
	Disable();
}

/// <summary>
/// 表示/非表示設定
/// </summary>
/// <param name="visible"></param>
void AItemBase::SetVisible(bool visible)
{
	UStaticMeshComponent* mesh = FindComponentByClass<UStaticMeshComponent>();
	if (mesh)
	{
		mesh->SetVisibility(visible, true);
	}
}

/// <summary>
/// 無効化する
/// 非表示となり何者とも干渉しなくなる
/// </summary>
void AItemBase::Disable()
{
	m_IsActive = false;
	SetVisible(false);
}
