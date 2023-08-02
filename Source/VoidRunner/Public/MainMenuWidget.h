// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* PlayButton;

public:
	//Setup code, binding events.
	UFUNCTION()
	void Setup();

	UFUNCTION()
	void OnStartClicked();
	
};
