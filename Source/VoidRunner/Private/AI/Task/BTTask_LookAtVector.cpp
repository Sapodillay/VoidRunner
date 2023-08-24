// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTTask_LookAtVector.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_LookAtVector::UBTTask_LookAtVector()
{
	NodeName = "Look At Vector";
}

EBTNodeResult::Type UBTTask_LookAtVector::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const FVector LookAtVector = OwnerComp.GetBlackboardComponent()->GetValueAsVector("PlayerLocation");
	APawn* EyePawn = OwnerComp.GetAIOwner()->GetPawn();

	if (!EyePawn)
	{
		return EBTNodeResult::Failed;
	}

	
	
	FVector LookAtDireciton = LookAtVector - EyePawn->GetActorLocation();
	FRotator TargetRotation = LookAtDireciton.Rotation();
	EyePawn->SetActorRotation(TargetRotation);
	
	return EBTNodeResult::Succeeded;
}