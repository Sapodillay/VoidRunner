// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTTask_Shoot.h"

#include "AIController.h"
#include "AI/GroundEnemyCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{

	NodeName = TEXT("Shoot");

	
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AGroundEnemyCharacter* GroundCharacter = Cast<AGroundEnemyCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	if (GroundCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	
	GroundCharacter->Attack();
	return EBTNodeResult::Succeeded;
}
