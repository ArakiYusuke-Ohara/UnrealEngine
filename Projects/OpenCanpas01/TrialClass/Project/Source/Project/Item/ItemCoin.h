// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemCoin.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AItemCoin : public AItemBase
{
	GENERATED_BODY()
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void Taked() override;

private:
	UPROPERTY(EditAnywhere)
	float m_RotationSpeed;


};
