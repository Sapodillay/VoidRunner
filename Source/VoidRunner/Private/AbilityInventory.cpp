// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityInventory.h"

// Sets default values for this component's properties
UAbilityInventory::UAbilityInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// Called when the game starts
void UAbilityInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbilityInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//Adds ability if slot if avaliable and returns true, else returns false.
bool UAbilityInventory::AddAbility(UAbility* Ability)
{
	if (!Ability) { return false; }
	if (!ActiveAbility)
	{
		ActiveAbility = Ability;
		return true;
	}
	return false;
}

void UAbilityInventory::UseAbility()
{
	//Test superjump
	//ActiveAbility = NewObject<UAbility>(this, SuperJumpAbility);
	if (ActiveAbility)
	{
		ActiveAbility->ActivateAbility();
		ActiveAbility = nullptr;
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("No ability in inventory"));
}

