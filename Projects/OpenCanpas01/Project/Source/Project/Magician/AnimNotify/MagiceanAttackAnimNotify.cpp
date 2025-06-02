// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiceanAttackAnimNotify.h"
#include "../Magician.h"

void UMagiceanAttackAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    if (AActor* Owner = MeshComp->GetOwner())
    {
         AMagician* magician = Cast<AMagician>(Owner);
         if (magician)
         {
             magician->FireBullet();
         }
    }
}
