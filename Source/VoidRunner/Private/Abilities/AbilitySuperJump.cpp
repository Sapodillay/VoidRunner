// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/AbilitySuperJump.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void UAbilitySuperJump::SetDefaultVelocity()
{
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	PlayerCharacter->GetCharacterMovement()->JumpZVelocity = 420.0f;
}

void UAbilitySuperJump::ActivateAbility()
{
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	PlayerCharacter->GetCharacterMovement()->JumpZVelocity = 1200.0f;
	PlayerCharacter->Jump();
	
	FTimerHandle TimerHandle;
	FTimerDelegate Delegate;
	Delegate.BindUFunction(this, "SetDefaultVelocity");
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, Delegate, 0.5f, false);
	UE_LOG(LogTemp, Warning, TEXT("RAN SUPER JUMP"))
}
