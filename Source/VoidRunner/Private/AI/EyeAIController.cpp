// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EyeAIController.h"

#include "BehaviorTree/BlackboardComponent.h"

void AEyeAIController::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
}

void AEyeAIController::BeginPlay()
{
	Super::BeginPlay();
	ClearFocus(EAIFocusPriority::Gameplay);
	if (AIBehaviour)
	{
		RunBehaviorTree(AIBehaviour);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}
