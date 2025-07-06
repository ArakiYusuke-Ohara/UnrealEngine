// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayCamera.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayCamera::APlayCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayCamera::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* playerController = UGameplayStatics::GetPlayerController(this, 0);
	if (playerController)
	{
		playerController->SetViewTargetWithBlend(this);
	}
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (player)
	{
		m_PosZ = player->GetActorLocation().Z;
	}
}

// Called every frame
void APlayCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// プレイヤーを追従する
	ACharacter* player = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (player)
	{
		FVector pos = {};
		pos = player->GetActorLocation();
		// ただしZ座標は固定
		pos.Z = m_PosZ;
		SetActorLocation(pos);
	}
}

