// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HittableComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedEvent, int, health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VOIDRUNNER_API UHittableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHittableComponent();

	//Getter
	int GetHealth() const;

	UPROPERTY(VisibleDefaultsOnly, Category = "Health Events")
	FOnHealthChangedEvent OnHealthChangedEvent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Health Events")
	FOnDeathEvent OnDeathEvent;

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	//Max health and starting health. Static.
	UPROPERTY(EditAnywhere, Category = Hittable)
	int maxHealth;

	//Current health, changes at runtime
	UPROPERTY(VisibleAnywhere, Category = Hittable)
	int currentHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Damage(int damage);

	//Setup component with max health.
	void Setup(int Health);
	
		
};
