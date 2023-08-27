// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Pickupable.generated.h"

UCLASS()
class VOIDRUNNER_API APickupable : public AActor
{
	GENERATED_BODY()

	//Added inside constructor
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAbility> Ability;

public:	
	// Sets default values for this actor's properties
	APickupable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnCollision(AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
