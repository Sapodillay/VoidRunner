// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GroundEnemyCharacter.h"

// Sets default values
AGroundEnemyCharacter::AGroundEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGroundEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGroundEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGroundEnemyCharacter::Attack()
{
	//
	FVector start = GetActorLocation();
	FVector end = start + GetActorForwardVector() * 1000.0f;
	DrawDebugLine(GetWorld(), start, end, FColor::Red, true, 3, 0,10.0f);
}

