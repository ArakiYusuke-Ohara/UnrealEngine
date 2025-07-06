// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMoveObject.h"
#include "../../Component/SimpleMoveComponent.h"

// Sets default values
ASimpleMoveObject::ASimpleMoveObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SimpleMoveComponent = CreateDefaultSubobject<USimpleMoveComponent>(TEXT("SimpleMove"));

	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	root->SetupAttachment(RootComponent);

	m_EndPoint = CreateDefaultSubobject<USceneComponent>(TEXT("EndPoint"));
	m_EndPoint->SetupAttachment(root);
}

// Called when the game starts or when spawned
void ASimpleMoveObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleMoveObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

