// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "BulletBase.generated.h"

UCLASS()
class PROJECT_API ABulletBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	bool IsActive() const { return m_Active; }
	int GetDamage() const { return m_Damage; }

	virtual void Fire(FVector pos, FRotator rot);

	virtual void Disable();

	UFUNCTION(BlueprintCallable)
	virtual void BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp, const FHitResult& hit);

private:
	void PlayHitEffect();

protected:
	UPROPERTY(EditAnywhere)
	float m_Life;

	UPROPERTY(EditAnywhere)
	float m_Damage;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_HitEffect;

	bool m_Active;
	float m_NowLife;
};
