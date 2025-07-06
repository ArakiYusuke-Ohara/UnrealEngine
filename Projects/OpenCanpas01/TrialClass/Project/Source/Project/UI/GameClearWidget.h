// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameClearWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class PROJECT_API UGameClearWidget : public UUserWidget
{
	GENERATED_BODY()
	
    UPROPERTY(meta = (BindWidget))
    UTextBlock* m_EnemyCountText;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* m_CoinCountText;
};
