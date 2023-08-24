// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EyeAIController.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API AEyeAIController : public AAIController
{
	GENERATED_BODY()

	virtual void Tick(float deltaSeconds) override;
	
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* AIBehaviour;
	
protected:
	virtual void BeginPlay() override;
	
};
