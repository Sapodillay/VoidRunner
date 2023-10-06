// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "EndingZone.generated.h"

UCLASS()
class VOIDRUNNER_API AEndingZone : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UBoxComponent* EndingTrigger;
	
public:	
	// Sets default values for this actor's properties
	AEndingZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnCollision(AActor* CollisionActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
