// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class VOIDRUNNER_API UAbility : public UObject
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "Ability")
    virtual void ActivateAbility();
	
};
