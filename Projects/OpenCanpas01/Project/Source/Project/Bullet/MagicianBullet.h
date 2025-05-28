// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletBase.h"
#include "MagicianBullet.generated.h"

class UProjectileMovementComponent;
class UNiagaraComponent;

/**
 * 
 */
UCLASS()
class PROJECT_API AMagicianBullet : public ABulletBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Fire(FVector pos, FRotator rot) override;
	virtual void Disable() override;

private:
	UProjectileMovementComponent* m_Movement;
	UNiagaraComponent* m_Niagara;
};
