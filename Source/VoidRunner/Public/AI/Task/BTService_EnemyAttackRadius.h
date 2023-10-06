// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_EnemyAttackRadius.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UBTService_EnemyAttackRadius : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_EnemyAttackRadius();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
