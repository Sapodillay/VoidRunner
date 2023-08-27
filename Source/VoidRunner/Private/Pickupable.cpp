// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickupable.h"

#include "AbilityInventory.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickupable::APickupable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set transfrom to default root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APickupable::BeginPlay()
{
	Super::BeginPlay();


}

void APickupable::OnCollision(AActor* OtherActor)
{

	AActor* PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if (OtherActor == PlayerActor)
	{
		UAbilityInventory* PlayerInventory = PlayerActor->FindComponentByClass<UAbilityInventory>();
		if (PlayerInventory)
		{
			//Test that the inventory is found
			if (PlayerInventory->AddAbility(NewObject<UAbility>(this, Ability)))
			{
				Destroy(true);
			}

		}

		
	}
}

// Called every frame
void APickupable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

