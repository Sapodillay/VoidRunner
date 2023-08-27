// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

#include "HittableComponent.h"


// Sets default values
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh->SetupAttachment(Root);
	
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::FireWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("Weapon fire"));
	
	FVector start = GetActorLocation();
	FVector end = start + GetActorForwardVector() * 1000.0f;

	FHitResult Hit;
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, start, end, ECC_Visibility);

	if (bHit)
	{
		const AActor* ActorHit = Hit.GetActor();

		if (UHittableComponent* Hittable = ActorHit->FindComponentByClass<UHittableComponent>())
		{
			// Draw the line.
			DrawDebugLine(GetWorld(), start, end, FColor::Green, true, 3, 0,10.0f);
			Hittable->Damage(5);
			return;
		}
	}
	
	// Draw the line.
	DrawDebugLine(GetWorld(), start, end, FColor::Red, true, 3, 0,10.0f);		
	
}

