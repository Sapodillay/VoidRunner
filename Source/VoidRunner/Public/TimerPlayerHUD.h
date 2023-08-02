// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API UTimerPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetTime(float time);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* TimerText;
	
};
