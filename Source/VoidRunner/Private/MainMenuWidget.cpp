// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "VoidGameInstance.h"
#include "Components/Button.h"


void UMainMenuWidget::Setup()
{

	PlayButton->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::OnStartClicked);
	
}

void UMainMenuWidget::OnStartClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Hiding mainMenu"))
	UVoidGameInstance* GameInstance = Cast<UVoidGameInstance>(GetGameInstance());
	GameInstance->TransitionState(EVoidGameState::Game);
}


