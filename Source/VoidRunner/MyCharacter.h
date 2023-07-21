// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Weapon.h"

#include "MyCharacter.generated.h"



class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AWeapon;

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
	UInputAction* ShootAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	float movementSpeed;

	UPROPERTY(EditAnywhere, Category = Input)
	float jumpHeight;
#pragma endregion InputPointers

	
	UPROPERTY(EditDefaultsOnly, Category = Weapon)
	TSubclassOf<AWeapon> WeaponClass;

	UPROPERTY()
	AWeapon* Weapon;
	
	//Input callbacks
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Jump();
	
	void Shoot();

	void SetupWeapon();
	
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
