// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SimpleMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_API USimpleMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USimpleMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	bool m_IsLoop;

	UPROPERTY(EditAnywhere)
	bool m_IsRoundTrip;

	UPROPERTY(EditAnywhere)
	float m_Time;

	UPROPERTY(EditAnywhere)
	UCurveFloat* m_MoveCurve;

	bool m_IsStop;
	int m_Direction;
	float m_TimeCount;
	FVector m_StartPos;
	FVector m_EndPos;
};
