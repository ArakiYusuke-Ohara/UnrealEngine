// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorEnemy.h"
#include "../Bullet/NormalBullet.h"

// Sets default values
AActorEnemy::AActorEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// HP‚ª0‚É‚È‚Á‚½‚ç€–S
	if (m_HP <= 0)
	{
		Destroy();
	}
}

/// <summary>
/// ƒqƒbƒg‚µ‚½‚Æ‚«‚Ìˆ—
/// BP‚©‚çŒÄ‚Î‚ê‚é
/// </summary>
/// <param name="otherActor">Õ“Ë‚µ‚½Actor</param>
void AActorEnemy::BeginOverlap(AActor* otherActor)
{
	// ANormalBullet‚ª“–‚½‚Á‚½‚©‚Ç‚¤‚©
	if (otherActor->IsA(ANormalBullet::StaticClass()))
	{
		// HP‚ğŒ¸‚ç‚·
		m_HP--;
	}
}

