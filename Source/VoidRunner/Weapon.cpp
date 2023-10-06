// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

#include "HittableComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"


// Sets default values
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	
	
	RootComponent = SkeletalMeshComponent;
	
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->SetSkeletalMesh(MeshInstance);
		SkeletalMeshComponent->SetRelativeLocation(FVector(60, 20, -40));
		SkeletalMeshComponent->SetRelativeRotation(FRotator(0, 270, 90));
	}
	if(!ImpactParticles)
	{
		//change to class default later.
		ImpactParticles = LoadObject<UParticleSystem>(NULL, TEXT("/Game/Realistic_Starter_VFX_Pack_Vol2/Particles/Blood/P_Blood_Splat_Cone.P_Blood_Splat_Cone"));
		if (ImpactParticles)
		{
			UE_LOG(LogTemp, Warning, TEXT("Particles loaded"))
		}
		
	}
	
}



// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::FireWeapon()
{
	//prevent shooting when reloading.
	if (hasShoot) { return; };
	
	hasShoot = true;
	
	FTimerHandle TimerHandle;
	float DelayInSeconds = 0.5f; // Delay time in seconds
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AWeapon::Reload, DelayInSeconds, false);

	FActorSpawnParameters SpawnParams;

	//Spawn projectile for trail
	//AActor* Projectile = GetWorld()->SpawnActor<ProjectileClass>(GetActorLocation(), GetActorRotation(), SpawnParams);
	//Projectile->SetActorLocation(GetActorForwardVector() * 1000.0f);
	
	
	

	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UCameraComponent* Camera = Player->FindComponentByClass<UCameraComponent>();
	
	FVector start = Camera->GetComponentLocation();
	FVector end = start + Camera->GetForwardVector() * 1000.0f;

	FHitResult Hit;
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, start, end, ECC_Visibility);

	if (bHit)
	{
		const AActor* ActorHit = Hit.GetActor();

		if (UHittableComponent* Hittable = ActorHit->FindComponentByClass<UHittableComponent>())
		{
			
			//spawn blood particles at hit location
			if (ImpactParticles && GetWorld() && ActorHit)
			{
				FRotator ParticleRotation = Hit.ImpactNormal.Rotation();
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, Hit.Location, ParticleRotation, FVector(2.0, 2.0, 2.0), true);
			}
			//DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 3, 0,10.0f);
			Hittable->Damage(5);
			
			return;
		}
	}
	
	// Draw the line.
	//DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 3, 0,10.0f);		
	
}

void AWeapon::Reload()
{
	hasShoot = false;
}

