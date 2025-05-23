// Fill out your copyright notice in the Description page of Project Settings.


#include "Magician.h"

// Sets default values
AMagician::AMagician()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMagician::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagician::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMagician::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

