// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "../Magician/Magician.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase::BeginOverlap(AActor* otherActor, UPrimitiveComponent* otherComp)
{
	// ƒvƒŒƒCƒ„[‚É“–‚½‚Á‚½
	if (otherActor->IsA(AMagician::StaticClass()))
	{
		Taked();
	}
}


void AItemBase::Taked()
{
	// æ‚ç‚ê‚½‚Æ‚«‚Ì‹¤’Êˆ—
	Destroy();
}
