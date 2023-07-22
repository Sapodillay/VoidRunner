// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HittableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOIDRUNNER_API UHittableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHittableComponent();

	//Getter
	int GetHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	//Max health and starting health. Static.
	UPROPERTY(EditDefaultsOnly, Category = Hittable)
	int maxHealth;

	//Current health, changes at runtime
	UPROPERTY(VisibleAnywhere, Category = Hittable)
	int currentHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Damage(int damage);
		
};
