// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTService_EnemyAttackRadius.h"

#include "AIController.h"
#include "AI/BaseEnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_EnemyAttackRadius::UBTService_EnemyAttackRadius()
{
	NodeName = "Returns radius if within enemy attack radius, else returns null";
}

void UBTService_EnemyAttackRadius::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	ABaseEnemyCharacter* EnemyCharacter = Cast<ABaseEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	const APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!PlayerPawn)
	{
		return;
	}
	if (!EnemyCharacter)
	{
		return;
	}
	const float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), EnemyCharacter->GetActorLocation());
	if (EnemyCharacter->AttackRadius > Distance)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}
