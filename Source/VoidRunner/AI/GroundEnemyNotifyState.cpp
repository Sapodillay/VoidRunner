// Fill out your copyright notice in the Description page of Project Settings.


#include "../AI/GroundEnemyNotifyState.h"

#include "AI/GroundEnemyCharacter.h"

void UGroundEnemyNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                          float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, __FUNCTION__);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AGroundEnemyCharacter* Enemy = Cast<AGroundEnemyCharacter>(MeshComp->GetOwner());
		if (Enemy != NULL)
		{
			Enemy->AttackDamage();
		}
	}
	
	
}

void UGroundEnemyNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, __FUNCTION__);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AGroundEnemyCharacter* Enemy = Cast<AGroundEnemyCharacter>(MeshComp->GetOwner());
		if (Enemy != NULL)
		{
			Enemy->bIsAttacking = false;
		}
	}

	
}
