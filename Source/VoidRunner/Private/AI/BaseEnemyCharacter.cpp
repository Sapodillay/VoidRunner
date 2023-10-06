// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BaseEnemyCharacter.h"
#include "HittableComponent.h"

#include "VoidGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Health Widget Component"));
	WidgetComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetComponent)
	{
		//Setup attachment and world position
		WidgetComponent->SetWorldLocation(GetActorLocation() + FVector(0.0f, 0.0f, 100.0f));
		WidgetComponent->SetWidgetClass(HealthBarWidgetClass);
		if (WidgetComponent->GetWidget())
		{
			WidgetComponent->GetWidget()->SetVisibility(ESlateVisibility::Hidden);
		}

		//Hide widget at start
	}

	//Register enemy to global enemy count.
	RegisterEnemy();

	UHittableComponent* HittableComponent = FindComponentByClass<UHittableComponent>();
	if (HittableComponent)
	{
		HittableComponent->OnDeathEvent.AddDynamic(this, &ABaseEnemyCharacter::OnDeath);
		HittableComponent->OnHealthChangedEvent.AddDynamic(this, &ABaseEnemyCharacter::UpdateHealthDisplay);
		if (WidgetComponent)
		{
			if (const UWorldHealthBarWidget* HealthWidget = Cast<UWorldHealthBarWidget>(WidgetComponent->GetWidget()))
			{
				if (HealthWidget)
				{
					HealthWidget->SetHealth(HittableComponent->GetHealth(),HittableComponent->GetMaxHealth());
				}
				
			}
		}
	}
	
}

//Register enemy to global enemy count.
void ABaseEnemyCharacter::RegisterEnemy()
{
	if (UVoidGameInstance* GameInstance = Cast<UVoidGameInstance>(GetGameInstance()))
	{
		GameInstance->AddEnemy(this);
	}
}

void ABaseEnemyCharacter::OnDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Destroying enemy from OnDeath() "))
	if (UVoidGameInstance* GameInstance = Cast<UVoidGameInstance>(GetGameInstance()))
	{
		GameInstance->RemoveEnemy(this);
	}
	Destroy();
	Cleanup();
}

void ABaseEnemyCharacter::Cleanup()
{
	
}

void ABaseEnemyCharacter::UpdateHealthDisplay(int Health)
{
	if (WidgetComponent->GetWidget())
	{
		WidgetComponent->GetWidget()->SetVisibility(ESlateVisibility::Visible);
	}
	if (const UHittableComponent* HittableComponent = FindComponentByClass<UHittableComponent>())
	{
		if (const UWorldHealthBarWidget* HealthWidget	= Cast<UWorldHealthBarWidget>(WidgetComponent->GetWidget()))
		{
			HealthWidget->SetHealth(HittableComponent->GetHealth(),HittableComponent->GetMaxHealth());
		}
	}
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		FVector PlayerLocation = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation();
		FVector ComponentLocation = WidgetComponent->GetComponentLocation();
		FRotator LookRot = UKismetMathLibrary::FindLookAtRotation(ComponentLocation, PlayerLocation);

		WidgetComponent->SetWorldRotation(LookRot);
		//Need to set position, problem with widget
		WidgetComponent->SetWorldLocation(GetActorLocation() + FVector(0.0f, 0.0f, 100.0f));		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find player."))
	}
}

// Called to bind functionality to input
void ABaseEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

