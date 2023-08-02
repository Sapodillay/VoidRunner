// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerPlayerHUD.h"

#include "Components/TextBlock.h"

void UTimerPlayerHUD::SetTime(float time)
{
	if (TimerText)
	{
		TimerText->SetText(FText::FromString(FString::SanitizeFloat(time)));
	}
}
