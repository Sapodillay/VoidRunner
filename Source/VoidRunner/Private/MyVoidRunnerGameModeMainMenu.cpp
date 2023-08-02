// Fill out your copyright notice in the Description page of Project Settings.


#include "MyVoidRunnerGameModeMainMenu.h"

#include "MainMenuWidget.h"
#include "VoidGameInstance.h"


AMyVoidRunnerGameModeMainMenu::AMyVoidRunnerGameModeMainMenu()
{

}

void AMyVoidRunnerGameModeMainMenu::StartPlay()
{
	//Access game instance, set mode to main menu.
	UVoidGameInstance* GameInstance = Cast<UVoidGameInstance>(GetGameInstance());
	GameInstance->ShowMainMenu();
}
