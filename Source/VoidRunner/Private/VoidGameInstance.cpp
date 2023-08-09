// Fill out your copyright notice in the Description page of Project Settings.


#include "VoidGameInstance.h"

#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"

//Move to an event.
void UVoidGameInstance::ShowMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Showing main menu"))
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

void UVoidGameInstance::TransitionState(EVoidGameState NewState)
{
	if (NewState == GameState)
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
		    //Move code to a state class
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
	
	switch (NewState)
	{
		case Startup: break;
		case MainMenu:
			{
				ShowMainMenu();
				break;
			}
		case Game: 
			{
				UE_LOG(LogTemp, Warning, TEXT("Loading level"))
				if (!LevelDataAsset)
				{
					UE_LOG(LogTemp, Warning, TEXT("No Level DataAsset found"))
					break;
				}
				UGameplayStatics::OpenLevel(GetWorld(), FName(LevelDataAsset->GetWorldName()), true);
			
			}
		default: ;
	}
	
	
	GameState = NewState;
}


