// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAttackAnimNotify.h"
#include "../EnemyBase.h"

void UEnemyAttackAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AActor* Owner = MeshComp->GetOwner())
    {
        AEnemyBase* enemy = Cast<AEnemyBase>(Owner);
        if (enemy)
        {
            enemy->Attack(m_AttackType);
        }
    }
}

