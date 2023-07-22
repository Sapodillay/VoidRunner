// Fill out your copyright notice in the Description page of Project Settings.


#include "HittableComponent.h"

// Sets default values for this component's properties
UHittableComponent::UHittableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHittableComponent::BeginPlay()
{
	Super::BeginPlay();

	//Set starting health, can move to different function later
	currentHealth = maxHealth;

	// ...
	
}


// Called every frame
void UHittableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//uint to prevent negative numbers.
void UHittableComponent::Damage(int damage)
{
	currentHealth = FGenericPlatformMath::Max(currentHealth - damage, 0);
	if (currentHealth == 0)
	{
		//death
		UE_LOG(LogTemp, Warning, TEXT("Death"))
	}
}

