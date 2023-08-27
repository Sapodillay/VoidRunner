// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HealthWidget.h"

#include "Components/TextBlock.h"


void UHealthWidget::UpdateHealth(int UpdatedHealth)
{

	//Check that HealthDisplay is set.
	if (HealthTextDisplay)
	{
		//Change to health template
		const FText FormattedString = FText::FromString(healthTemplate);
		
		HealthTextDisplay->SetText(FText::Format(FormattedString, UpdatedHealth));
	}
	
}
