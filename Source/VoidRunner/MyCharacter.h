// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityInventory.h"
#include "HittableComponent.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Weapon.h"

#include "MyCharacter.generated.h"



class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AWeapon;

class UHealthWidget;

UCLASS(config=Game)
class VOIDRUNNER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()
	
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;
	
	
public:
	// Sets default values for this character's properties
	AMyCharacter(const FObjectInitializer& object_initalizer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#pragma region InputPoints
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputMappingContext* MovementContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MovementAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* AbilityAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* ShootAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	float movementSpeed;

	UPROPERTY(EditAnywhere, Category = Input)
	float jumpHeight;
#pragma endregion InputPointers

	//Refactor to widget, not HUD
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UTimerPlayerHUD> PlayerHUDClass;

	UPROPERTY()
	class UTimerPlayerHUD* PlayerHUD;
	
	UPROPERTY(EditDefaultsOnly, Category = Weapon)
	TSubclassOf<AWeapon> WeaponClass;

	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UHealthWidget> HealthWidgetClass;

	UPROPERTY()
	class UHealthWidget* HealthWidget;

	UPROPERTY(VisibleAnywhere)
	UHittableComponent* HitComponent;

	UPROPERTY(VisibleAnywhere)
	UAbilityInventory* AbilityInventory;
	

	UPROPERTY()
	AWeapon* Weapon;
	
	
	//Input callbacks
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Jump();
	
	void Shoot();

	void SetupWeapon();

	void UseAbility();

	float TimerTime = 0;
	void TimeTest();

	UFUNCTION()
	void OnDeath();
	UFUNCTION()
	void OnHealthChanged(int Health);
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
