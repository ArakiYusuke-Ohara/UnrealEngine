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

void AItemBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	if (!m_IsActive)return;

	// プレイヤーに当たった
	if (otherActor->IsA(AMagician::StaticClass()))
	{
		Taked();
	}
}

void AItemBase::Respawn()
{
	SetActorTransform(m_RespawnTransform);

	// アクティブと表示
	m_IsActive = true;
	SetVisible(true);
}

void AItemBase::Taked()
{
	// ゲットエフェクト
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), m_GetEffect, GetActorLocation());

	// 非アクティブと非表示
	m_IsActive = false;
	SetVisible(false);
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
