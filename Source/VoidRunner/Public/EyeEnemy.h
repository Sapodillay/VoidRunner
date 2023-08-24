// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EyeEnemy.generated.h"

UCLASS()
class VOIDRUNNER_API AEyeEnemy : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	float detectionRadius;

	UPROPERTY(EditDefaultsOnly)
	float rotationSpeed;

	UFUNCTION()
	void OnLevelStart();
	UFUNCTION()
	bool IsPlayerAttackable();
	UFUNCTION()
	void Attack();
	UFUNCTION()
	void Shake(float amplitude, float frequency);

	UPROPERTY(EditDefaultsOnly)
	float shakeAmount;
	
	UPROPERTY(EditDefaultsOnly)
	float shakeFrequency;

	UPROPERTY(VisibleAnywhere)
	float charge;

	UPROPERTY(EditDefaultsOnly)
	float chargeNeeeded;

	UPROPERTY()
	FVector startingLocation;

	ACharacter* PlayerActor;
	
public:	
	// Sets default values for this actor's properties
	AEyeEnemy();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
