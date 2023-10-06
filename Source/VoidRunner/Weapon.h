// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

#include "Weapon.generated.h"

UCLASS()
class VOIDRUNNER_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon();
	void FireWeapon();

	UFUNCTION()
	void Reload();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	bool hasShoot;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> ProjectileClass;


	UPROPERTY(EditDefaultsOnly)
	FRotator RotatorOffset;

	UPROPERTY(EditDefaultsOnly)
	FVector LocationOffset;
	
	UPROPERTY(EditDefaultsOnly)
	USkeletalMesh* MeshInstance;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere)
	UParticleSystem* ImpactParticles;
	
};
