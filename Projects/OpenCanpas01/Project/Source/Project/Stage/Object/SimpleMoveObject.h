// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleMoveObject.generated.h"

class USimpleMoveComponent;

UCLASS()
class PROJECT_API ASimpleMoveObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleMoveObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	const USceneComponent* GetEndPoint() const { return m_EndPoint; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* m_EndPoint;

	UPROPERTY(VisibleAnywhere)
	USimpleMoveComponent* m_SimpleMoveComponent;
};
