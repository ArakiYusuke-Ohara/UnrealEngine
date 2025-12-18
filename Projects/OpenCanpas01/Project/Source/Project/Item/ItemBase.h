// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "ItemBase.generated.h"

class UItemManager;

UCLASS()
class PROJECT_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Taked();

	void SetVisible(bool visible);
	void Disable();

	UItemManager* GetItemManager();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp);

	void Respawn();

protected:
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* m_GetEffect;

	bool m_IsActive;
	FTransform m_RespawnTransform;
};
