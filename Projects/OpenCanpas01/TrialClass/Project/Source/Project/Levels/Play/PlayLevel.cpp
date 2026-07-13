// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayLevel.h"
#include "PlayCounter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "../../Audio/AudioManager.h"
#include "../../Magician/Magician.h"
#include "../../Enemy/EnemyManager.h"
#include "../../Item/ItemManager.h"

// Sets default values
APlayLevel::APlayLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayLevel::BeginPlay()
{
	Super::BeginPlay();
	
	m_Player = Cast<AMagician>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	// BGM再生
	auto* audio = GetGameInstance()->GetSubsystem<UAudioManager>();
	if (audio)
	{
		audio->PlayBGM(m_BGM);
	}
}

void APlayLevel::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void APlayLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// プレイヤーが死亡したら一定時間後にフェードアウト
	if (m_State != PlayLevelState::PLAYER_DEAD && m_Player->IsDead())
	{
		float waitTime = m_Player->IsFallingDead() ? 0.1f : 3.0f;
		m_State = PlayLevelState::PLAYER_DEAD;
		GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &APlayLevel::FadeOut, waitTime, false);
	}
	// ステージリトライ
	else if (m_State != PlayLevelState::RETRY && m_Player->IsRetry())
	{
		m_State = PlayLevelState::RETRY;
		APlayLevel::FadeOut();
	}
}

void APlayLevel::FadeOut()
{
	ALevelBase::FadeOut();

	// UIをリセット
	UWidgetLayoutLibrary::RemoveAllWidgets(this);

	// 指定時間後に再始動
	GetWorld()->GetTimerManager().SetTimer(m_TimerHandle, this, &APlayLevel::Restart, 1.5f, false);
}

void APlayLevel::Restart()
{
	m_State = PlayLevelState::PLAY;

	// プレイヤーをリスポーン
	m_Player->Respawn();

	// エネミーをリスポーン
	UEnemyManager* enemyManager = GetWorld()->GetSubsystem<UEnemyManager>();
	if (enemyManager) enemyManager->RespawnAllEnemy();

	// アイテムをリスポーン
	UItemManager* itemManager = GetWorld()->GetSubsystem<UItemManager>();
	if (itemManager) itemManager->RespawnAllItem();

	// カウンターをリセット
	UPlayCounter* playCounter = GetWorld()->GetSubsystem<UPlayCounter>();
	playCounter->ResetCounter();

	// フェードイン
	ALevelBase::FadeIn();
}
