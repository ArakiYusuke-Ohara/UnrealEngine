// Fill out your copyright notice in the Description page of Project Settings.


#include "TestMap.h"
#include "../GameInstance/MyGameInstance.h"
#include "../Magician/Magician.h"
#include "../Enemy/EnemyManager.h"
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
	
	UMyGameInstance* gameInstance = Cast<UMyGameInstance>(GetGameInstance());
	gameInstance->CreateBulletManager();

	m_State = PlayMapState::PLAY;

	m_Player = Cast<AMagician>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ATestMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// プレイヤーが死亡したら一定時間後にフェードアウト
	if (m_State == PlayMapState::PLAY && m_Player->IsDead())
	{
		m_State = PlayMapState::PLAYER_DEAD;
		GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &ATestMap::FadeOut, 3.0f, false);
	}
}

void ATestMap::FadeOut()
{
	m_State = PlayMapState::FADE_OUT;

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
	m_State = PlayMapState::PLAY;

	// プレイヤーをリスポーン
	m_Player->Respawn();

	// エネミーをリスポーン
	AEnemyManager::GetInstance(GetWorld())->RespawnAllEnemy();

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

	UMyGameInstance* gameInstance = Cast<UMyGameInstance>(GetGameInstance());

	if (gameInstance)
	{
		gameInstance->DeleteBulletManager();
	}
}
