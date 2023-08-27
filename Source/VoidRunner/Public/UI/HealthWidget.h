// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* HealthTextDisplay;

	UPROPERTY(EditDefaultsOnly)
	FString healthTemplate;

public:

	//Update health amount in the UI
	UFUNCTION()
	void UpdateHealth(int UpdatedHealth);

	
};
