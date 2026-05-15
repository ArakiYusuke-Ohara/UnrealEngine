// Fill out your copyright notice in the Description page of Project Settings.


#include "TestMap.h"
#include "../Magician/Magician.h"
#include "../Enemy/EnemyManager.h"
#include "../Item/ItemManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATestMap::ATestMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestMap::BeginPlay()
{
	Super::BeginPlay();
	
	m_State = TestMapState::PLAY;

	m_Player = Cast<AMagician>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ATestMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// プレイヤーが死亡したら一定時間後にフェードアウト
	if (m_State == TestMapState::PLAY && m_Player->IsDead())
	{
		float waitTime = m_Player->IsFallingDead() ? 0.1f : 3.0f;
		m_State = TestMapState::PLAYER_DEAD;
		GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &ATestMap::FadeOut, waitTime, false);
	}
}

void ATestMap::FadeOut()
{
	m_State = TestMapState::FADE_OUT;

	// フェードアウト
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (playerController && playerController->PlayerCameraManager)
	{
		playerController->PlayerCameraManager->StartCameraFade(0.0f, 1.0f, 1.0f, FLinearColor::Black, false, true);
	}

	// 指定時間後に再始動
	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &ATestMap::Restart, 1.5f, false);
}


void ATestMap::Restart()
{
	m_State = TestMapState::PLAY;

	// プレイヤーをリスポーン
	m_Player->Respawn();

	// エネミーをリスポーン
	UEnemyManager* enemyManager = GetWorld()->GetSubsystem<UEnemyManager>();
	if (enemyManager) enemyManager->RespawnAllEnemy();

	// アイテムをリスポーン
	UItemManager* itemManager = GetWorld()->GetSubsystem<UItemManager>();
	if (itemManager) itemManager->RespawnAllItem();

	// フェードイン
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (playerController && playerController->PlayerCameraManager)
	{
		playerController->PlayerCameraManager->StartCameraFade(1.0f, 0.0f, 1.0f, FLinearColor::Black, false, true);
	}

}

void ATestMap::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
