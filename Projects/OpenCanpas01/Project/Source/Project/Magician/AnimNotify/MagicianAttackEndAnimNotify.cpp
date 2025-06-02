// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicianAttackEndAnimNotify.h"
#include "../Magician.h"

void UMagicianAttackEndAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AActor* Owner = MeshComp->GetOwner())
    {
        AMagician* magician = Cast<AMagician>(Owner);
        if (magician)
        {
            magician->EndAttack();
        }
    }
}
