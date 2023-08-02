// Fill out your copyright notice in the Description page of Project Settings.


#include "VoidGameInstance.h"

#include "MainMenuWidget.h"

//Move to an event.
void UVoidGameInstance::ShowMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Showing main menu"))
	TransitionState(MainMenu);
	//Get player controller
	APlayerController* PlayerController = GetPrimaryPlayerController();
	check(PlayerController);
	//Create menuHUD based on MainMenuHUDClass
	MainMenuHUD = CreateWidget<UMainMenuWidget>(PlayerController, MainMenuHUDClass);
	check(MainMenuHUD);
	//Add to screen, call setup code and set input mode
	MainMenuHUD->AddToPlayerScreen();
	MainMenuHUD->Setup();
	PlayerController->SetInputMode(FInputModeUIOnly());
}

void UVoidGameInstance::TransitionState(EVoidGameState State)
{
	if (State == GameState)
	{
		//State is same, don't do anything
		UE_LOG(LogTemp, Warning, TEXT("Tried to transition to the same state"));
		return;
	}

	//State transitioning from.
	switch (GameState)
	{
		case Startup: break;
		{
			//Hide
		}
		case MainMenu:
		{
			UE_LOG(LogTemp, Warning, TEXT("Transitioning from Menu"));
			//Hide main menu
			if (MainMenuHUD)
			{
				UE_LOG(LogTemp, Warning, TEXT("Setting visibility..."));
				MainMenuHUD->SetVisibility(ESlateVisibility::Hidden);
				GetPrimaryPlayerController()->SetInputMode(FInputModeGameOnly());
			}
			break;
		}
		case Game: break;
		{
			
		}
		default: ;
	}
	GameState = State;
}


