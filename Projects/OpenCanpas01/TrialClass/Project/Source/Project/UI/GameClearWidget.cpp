// Fill out your copyright notice in the Description page of Project Settings.


#include "GameClearWidget.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"
#include "../Levels/Play/PlayCounter.h"
#include "../Enemy/EnemyManager.h"
#include "../Item/ItemManager.h"

void UGameClearWidget::NativeConstruct()
{
	UPlayCounter* playCounter = GetWorld()->GetSubsystem<UPlayCounter>();

	if (playCounter && playCounter->IsStageComplete())
	{
		// クリア側を非表示にする
		m_ClearOverlay->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		// コンプリート側を非表示にする
		m_CompleteOverlay->SetVisibility(ESlateVisibility::Collapsed);
		// 残数を表示
		UItemManager* itemManager = GetWorld()->GetSubsystem<UItemManager>();
		int coinMax = itemManager->GetCoinMax();
		int getCoin = playCounter->GetCoin();
		if (getCoin >= coinMax)
		{
			// 全部取ってた場合
			FText text = FText::FromString(FString::Printf(TEXT("コインはぜんぶとってるよ")));
			m_CoinLeft->SetText(text);
		}
		else
		{
			// 全部取ってない場合
			FText text = FText::FromString(FString::Printf(TEXT("だけどコインがあと%d枚のこってるよ"), coinMax - getCoin));
			m_CoinLeft->SetText(text);
		}

		UEnemyManager* enemyManager = GetWorld()->GetSubsystem<UEnemyManager>();
		int enemyMax = enemyManager->GetEnemyMax();
		int killEnemy = playCounter->GetKillEnemy();
		if (killEnemy >= enemyMax)
		{
			// 全部倒した場合
			FText text = FText::FromString(FString::Printf(TEXT("てきはぜんぶたおしたよ")));
			m_EnemyLeft->SetText(text);
		}
		else
		{
			// 全部倒してない場合
			FText text = FText::FromString(FString::Printf(TEXT("だけどてきがあと%d体のこってるよ"), enemyMax - killEnemy));
			m_EnemyLeft->SetText(text);
		}
	}

}
