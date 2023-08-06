// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoidGameState.h"
#include "Engine/GameInstance.h"
#include "VoidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UVoidGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UPROPERTY()
	class UMainMenuWidget* MainMenuHUD;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainMenuWidget> MainMenuHUDClass;

public:
	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<EVoidGameState> GameState;

	void ShowMainMenu();

	void TransitionState(EVoidGameState NewState);



	
};
