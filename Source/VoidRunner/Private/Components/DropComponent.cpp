// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DropComponent.h"

#include "HittableComponent.h"

// Sets default values for this component's properties
UDropComponent::UDropComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDropComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("begin play event ran"))

	//Check if actor has Hittable component, required for it to work
	if (UHittableComponent* HittableComponent = GetOwner()->FindComponentByClass<UHittableComponent>())
	{
		UE_LOG(LogTemp, Warning, TEXT("registering OnDeath event"))

		HittableComponent->OnDeathEvent.AddDynamic(this, &UDropComponent::OnDeath);
	}
}

void UDropComponent::OnDeath()
{
	//Drop pickupable actor at location of death.

	UE_LOG(LogTemp, Warning, TEXT("Spawning pickupable actor"))

	const FVector Location = GetOwner()->GetActorLocation();
	const FRotator Rotator = GetOwner()->GetActorRotation();
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<APickupable>(DropPickupable, Location, Rotator, SpawnParams);
	
}


// Called every frame
void UDropComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

