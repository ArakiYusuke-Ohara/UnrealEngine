// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyDamageAnimNotify.h"
#include "../EnemyBase.h"

void UEnemyDamageAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AActor* Owner = MeshComp->GetOwner())
    {
        AEnemyBase* enemy = Cast<AEnemyBase>(Owner);
        if (enemy)
        {
            enemy->EndDamage();
        }
    }
}
