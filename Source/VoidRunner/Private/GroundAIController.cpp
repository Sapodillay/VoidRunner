// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundAIController.h"

#include "BehaviorTree/BlackboardComponent.h"


void AGroundAIController::BeginPlay()
{
	Super::BeginPlay();
	ClearFocus(EAIFocusPriority::Gameplay);
	if (AIBehaviour)
	{
		RunBehaviorTree(AIBehaviour);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AGroundAIController::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
	
}
