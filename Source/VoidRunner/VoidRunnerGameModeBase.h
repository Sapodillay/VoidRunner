// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VoidRunnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VOIDRUNNER_API AVoidRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;

	AVoidRunnerGameModeBase(const FObjectInitializer& ObjectInitializer);
	
	
};
