// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilitySuperJump.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UAbilitySuperJump : public UAbility
{
	GENERATED_BODY()

	UFUNCTION()
	void SetDefaultVelocity();
	
public:
	virtual void ActivateAbility() override;
	
};
