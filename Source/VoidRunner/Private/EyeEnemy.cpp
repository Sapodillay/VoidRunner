// Fill out your copyright notice in the Description page of Project Settings.


#include "EyeEnemy.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void AEyeEnemy::OnLevelStart()
{
	PlayerActor = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	startingLocation = GetActorLocation();
	
}

bool AEyeEnemy::IsPlayerAttackable()
{
	if (!PlayerActor) return false;
	
	FVector start = GetActorLocation();
	FVector direction = (PlayerActor->GetActorLocation() - start);
	direction.Normalize();
	FVector end = start + (direction * detectionRadius);
	FHitResult Hit;
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, start, end, ECC_Camera);

	if (bHit)
	{
		return true;
	}
	return false;
}

// Sets default values
AEyeEnemy::AEyeEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEyeEnemy::Attack()
{
	DrawDebugLine(GetWorld(), GetActorLocation(), PlayerActor->GetActorLocation(), FColor::Green, true, 3, 0,10.0f);
	charge = 0;
}

void AEyeEnemy::Shake(float amplitude, float frequency)
{
	// Calculate the shaking offset
	float Offset = amplitude * FMath::Sin(frequency);

	FVector Location = GetActorLocation();
	Location.Z = startingLocation.Z + Offset;
	SetActorLocation(Location);
}

// Called when the game starts or when spawned
void AEyeEnemy::BeginPlay()
{
	Super::BeginPlay();
	OnLevelStart();
}

// Called every frame
void AEyeEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerActor) return;
	if (IsPlayerAttackable())
	{
		if(charge==chargeNeeeded)
		{
			Attack();	
		}
		FVector LookAtDireciton = PlayerActor->GetActorLocation() - GetActorLocation();
		FRotator TargetRotation = LookAtDireciton.Rotation();
		FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, rotationSpeed);
		SetActorRotation(NewRotation);
		charge++;
	}
	else
	{
		charge--;
		charge = FMath::Max(charge, 0);
	}
	Shake(shakeAmount, charge * shakeFrequency);
}

