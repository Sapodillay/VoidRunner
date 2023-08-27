// Fill out your copyright notice in the Description page of Project Settings.



#include "AI/GroundEnemyCharacter.h"
#include "HittableComponent.h"

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

	//Register to hit component.
	if (UHittableComponent* HittableComponent = FindComponentByClass<UHittableComponent>())
	{
		HittableComponent->OnDeathEvent.AddDynamic(this, &AGroundEnemyCharacter::OnDeath);
	}
	
}

// Called every frame
void AGroundEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGroundEnemyCharacter::OnDeath()
{
	Destroy();
}

void AGroundEnemyCharacter::Attack()
{
	//
	const FVector Start = GetActorLocation();
	const FVector OffsetStart = Start + GetActorForwardVector() * 50.0f;
	const FVector End = Start + GetActorForwardVector() * 1000.0f;

	UE_LOG(LogTemp, Warning, TEXT("enemy fire"));
	
	FHitResult Hit;
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, OffsetStart, End, ECC_Pawn);

	if (bHit)
	{
		const AActor* ActorHit = Hit.GetActor();

		
		if (UHittableComponent* Hittable = ActorHit->FindComponentByClass<UHittableComponent>())
		{
			UE_LOG(LogTemp, Warning, TEXT("hit player"));
			// Draw the line.
			DrawDebugLine(GetWorld(), OffsetStart, End, FColor::Green, true, 3, 0,10.0f);
			Hittable->Damage(5);
			return;
		}
	}
	
	// Draw the line.
	DrawDebugLine(GetWorld(), OffsetStart, End, FColor::Red, true, 3, 0,10.0f);		
}

