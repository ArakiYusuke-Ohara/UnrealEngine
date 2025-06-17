// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyEnemyMoveComponent.h"
#include "../Enemy/EnemyBase.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UFlyEnemyMoveComponent::UFlyEnemyMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFlyEnemyMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AEnemyBase* enemy = Cast<AEnemyBase>(GetOwner());
	if (enemy)
	{
		// ”z’uêŠ‚ðŠo‚¦‚Ä‚¨‚­
		m_StartPos = enemy->GetActorLocation();

		// ‘¼‚ÉMovement‚ª‚Â‚¢‚Ä‚¢‚éê‡‚Í–³Œø‚É‚·‚é
		UCharacterMovementComponent* movement = enemy->GetCharacterMovement();
		if (movement)
		{
			movement->DisableMovement();
		}
	}
}


// Called every frame
void UFlyEnemyMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AEnemyBase* enemy = Cast<AEnemyBase>(GetOwner());

	if (!enemy || enemy->IsStop()) return;

	FVector pos = m_StartPos;

	if (m_IsYMove)
	{
		pos.Y = m_StartPos.Y + FMath::Cos(m_Angle) * m_Radius;
	}
	if (m_IsZMove)
	{
		pos.Z = m_StartPos.Z + FMath::Sin(m_Angle) * m_Radius;
	}

	enemy->SetActorLocation(pos);

	m_Angle += 2.0f * PI * (DeltaTime / m_Time);
	m_Angle = FMath::Wrap(m_Angle, 0.0f, 2.0f * PI);

}

