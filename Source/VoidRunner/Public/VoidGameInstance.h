// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelDataAsset.h"
#include "VoidGameState.h"
#include "AI/BaseEnemyCharacter.h"
#include "Engine/GameInstance.h"
#include "VoidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UVoidGameInstance : public UGameInstance
{
	GENERATED_BODY()


	//Enemy list
	UPROPERTY()
	TArray<ABaseEnemyCharacter*> EnemyList;
	

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

	void ShowGameOver(bool IsGameOver);

	void TransitionState(EVoidGameState NewState);

	//Adds enemy to global enemy count
	UFUNCTION()
	void AddEnemy(ABaseEnemyCharacter* Enemy);
	UFUNCTION()
	void RemoveEnemy(ABaseEnemyCharacter* Enemy);
	
	//Returns true if all enemies in the level are dead.
	UFUNCTION()
	bool IsCleared() const;



	
};
