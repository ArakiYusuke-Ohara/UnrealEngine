// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "EnemyAttackAnimNotify.generated.h"

UENUM(BlueprintType)
enum class EEnemyAttackType : uint8
{
	AttackA UMETA(DisplayName = "Attack A"),
	AttackB UMETA(DisplayName = "Attack B"),
	AttackC UMETA(DisplayName = "Attack C"),
};

/**
 * 
 */
UCLASS()
class PROJECT_API UEnemyAttackAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	EEnemyAttackType m_AttackType;
};
