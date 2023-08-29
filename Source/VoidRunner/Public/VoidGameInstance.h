// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelDataAsset.h"
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

	UPROPERTY()
	class UGameOverUI* GameOverUI;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameOverUI> GameOverUIClass;

	UPROPERTY(EditAnywhere)
	ULevelDataAsset* LevelDataAsset;

public:
	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<EVoidGameState> GameState;

	void ShowMainMenu();

	void ShowGameOver();

	void TransitionState(EVoidGameState NewState);



	
};
