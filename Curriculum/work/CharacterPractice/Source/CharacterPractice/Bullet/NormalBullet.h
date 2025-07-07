// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletParameter.h"
#include "NiagaraSystem.h"
#include "NormalBullet.generated.h"

UCLASS(Blueprintable)
class CHARACTERPRACTICE_API ANormalBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANormalBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Fire(FVector pos, FRotator rot);

	bool IsActive() const { return m_Active; }

private:
	void DisableBullet();

protected:
	UFUNCTION(BlueprintCallable)
	void BeginOverlap(AActor* otherActor);

private:
	UPROPERTY(EditAnywhere)
	float m_Life;

	UPROPERTY(EditAnywhere)
	float m_Speed;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_HitEffect;

	bool m_Active;
	float m_NowLife;
};
