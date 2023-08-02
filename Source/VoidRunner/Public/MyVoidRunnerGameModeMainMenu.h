// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../VoidRunnerGameModeBase.h"
#include "MyVoidRunnerGameModeMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API AMyVoidRunnerGameModeMainMenu : public AVoidRunnerGameModeBase
{
	GENERATED_BODY()

	AMyVoidRunnerGameModeMainMenu();
	
	virtual void StartPlay() override;
	
};
