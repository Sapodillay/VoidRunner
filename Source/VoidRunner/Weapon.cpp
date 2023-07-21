// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"


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

	// Color of the line.
	FColor color = FColor::Red;

	// Thickness of the line.
	float thickness = 10.0f;

	// Duration of the line.
	int32 duration = 3;

	// Draw the line.
	DrawDebugLine(GetWorld(), start, end, color, true, duration, 0,thickness);
}

