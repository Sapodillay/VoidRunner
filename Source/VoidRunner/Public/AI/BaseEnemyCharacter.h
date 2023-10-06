// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "UI/WorldHealthBarWidget.h"
#include "BaseEnemyCharacter.generated.h"

UCLASS()
class VOIDRUNNER_API ABaseEnemyCharacter : public ACharacter
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UWorldHealthBarWidget> HealthBarWidgetClass;

	
	//Offset from the enemy that the widget is.
	UPROPERTY(EditDefaultsOnly)
	FVector WidgetOffset = FVector(0.0f, 0.0f, 100.0f);

	//Scale size of the widget
	UPROPERTY(EditDefaultsOnly)
	FVector WidgetScale = FVector(0.3f, 0.3f, 0.3f);
	
	UPROPERTY(EditDefaultsOnly)
	UWidgetComponent* WidgetComponent;
	
public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

	

	UPROPERTY(EditDefaultsOnly)
	float AttackRadius;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	


	UFUNCTION()
	void RegisterEnemy();

	UFUNCTION()
	virtual void OnDeath();
	
	virtual void Cleanup();

	UFUNCTION()
	void UpdateHealthDisplay(int Health);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
