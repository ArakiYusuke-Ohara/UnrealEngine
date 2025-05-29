// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletBase.h"
#include "NiagaraComponent.h"
#include "MagicianBullet.generated.h"

class UProjectileMovementComponent;

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
	UStaticMeshComponent* m_Mesh;
	UProjectileMovementComponent* m_Movement;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_Particle;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_EndEffect;

	UNiagaraComponent* m_ParticleComponent;
};
