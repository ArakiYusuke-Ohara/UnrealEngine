// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicianDamageEndAnimNotify.h"
#include "../Magician.h"

void UMagicianDamageEndAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AActor* Owner = MeshComp->GetOwner())
    {
        AMagician* magician = Cast<AMagician>(Owner);
        if (magician)
        {
            magician->EndDamage();
        }
    }
}
