// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Components/ActorComponent.h"
#include "Abilities/AbilitySuperJump.h"
#include "AbilityInventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOIDRUNNER_API UAbilityInventory : public UActorComponent
{
	GENERATED_BODY()
	
	//TQueue<UAbility*> AbilityQueue;

	UPROPERTY(VisibleAnywhere)
	UAbility* ActiveAbility;


public:	
	// Sets default values for this component's properties
	UAbilityInventory();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	bool AddAbility(UAbility* Ability);

	UFUNCTION()
	void UseAbility();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

		
};
