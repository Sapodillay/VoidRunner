// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LevelDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API ULevelDataAsset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString LevelName;

	UPROPERTY(EditAnywhere)
	float TimeToBeat;

public:
	
	UFUNCTION()
	FString GetWorldName();
	
};
