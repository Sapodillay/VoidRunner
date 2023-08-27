// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/BTService_PlayerLocationRadius.h"

#include "AIController.h"
#include "AI/EyeEnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


UBTService_PlayerLocationRadius::UBTService_PlayerLocationRadius()
{
	NodeName = "Get player location in radius";
}

void UBTService_PlayerLocationRadius::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	AEyeEnemyCharacter* EyeEnemyPawn = Cast<AEyeEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	const APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (!PlayerPawn)
	{
		return;
	}
	if (!EyeEnemyPawn)
	{
		return;
	}

	const float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), EyeEnemyPawn->GetActorLocation());

	if (EyeEnemyPawn->attackRadius > Distance)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}

	
}
