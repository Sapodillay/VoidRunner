// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickupable.h"
#include "Components/ActorComponent.h"
#include "DropComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOIDRUNNER_API UDropComponent : public UActorComponent
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)
	TSubclassOf<APickupable> DropPickupable;
	
public:	
	// Sets default values for this component's properties
	UDropComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnDeath();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
