// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameClearWidget.generated.h"

class UTextBlock;
class UOverlay;

/**
 * 
 */
UCLASS()
class PROJECT_API UGameClearWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

private:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* m_CoinLeft;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* m_EnemyLeft;

    UPROPERTY(meta = (BindWidget))
    UOverlay* m_ClearOverlay;

    UPROPERTY(meta = (BindWidget))
    UOverlay* m_CompleteOverlay;

};
