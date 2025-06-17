// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAttackEndAnimNotify.h"
#include "../EnemyBase.h"

void UEnemyAttackEndAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AActor* Owner = MeshComp->GetOwner())
    {
        AEnemyBase* enemy = Cast<AEnemyBase>(Owner);
        if (enemy)
        {
            enemy->EndAttack();
        }
    }
}
