// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "TimerPlayerHUD.h"
#include "UI/HealthWidget.h"
#include "Blueprint/UserWidget.h"

//Input includes
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
AMyCharacter::AMyCharacter(const FObjectInitializer& ObjectInitalizer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	HitComponent = CreateDefaultSubobject<UHittableComponent>(FName("Hit Component"));

	AbilityInventory = CreateDefaultSubobject<UAbilityInventory>(FName("Ability Inventory"));

	//HUD
	PlayerHUD = nullptr;
	PlayerHUDClass = nullptr;

	HealthWidget = nullptr;
	HealthWidgetClass = nullptr;
	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{

	if (HitComponent)
	{
		//remove magic numbers later.
		HitComponent->Setup(100);
	}
	
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyCharacter::TimeTest, 1.0f, true, 0);

	Super::BeginPlay();
	//Setup inputs
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			 Subsystem->AddMappingContext(MovementContext, 0);
		}
	}
	//Setup weapon
	SetupWeapon();

	//Setup UI
	if (IsLocallyControlled())
	{
		if (PlayerHUDClass)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Controller);
			check(PlayerController);
			PlayerHUD = CreateWidget<UTimerPlayerHUD>(PlayerController, PlayerHUDClass);
			check(PlayerHUD);
			PlayerHUD->AddToPlayerScreen();			
		}
		if (HealthWidgetClass)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Controller);
			check(PlayerController);
			HealthWidget = CreateWidget<UHealthWidget>(PlayerController, HealthWidgetClass);
			check(HealthWidget);
			HealthWidget->AddToPlayerScreen();
			//Set starting health
			HealthWidget->UpdateHealth(HitComponent->GetHealth());
		}

	}

	//Register health events.
	
	if (HitComponent)
	{
		HitComponent->OnDeathEvent.AddDynamic(this, &AMyCharacter::OnDeath);
		HitComponent->OnHealthChangedEvent.AddDynamic(this, &AMyCharacter::OnHealthChanged);
	}
	
}

void AMyCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromParent();
		PlayerHUD = nullptr;
	}
	
}

void AMyCharacter::Move(const FInputActionValue& Value)
{

	if (Controller == nullptr) { return; }
	
	//Get movement vector from ActionValue
	const FVector2D MovementVector = Value.Get<FVector2D>();

	//Get the rotation of the player controller
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	//Convert controller forward rotation to unit forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, MovementVector.Y);
	//get right vector from controller rotation
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, MovementVector.X);
	
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
	if (Controller == nullptr) { return; }
	
	const FVector2D LookVector = Value.Get<FVector2D>();
	
	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void AMyCharacter::Jump()
{
	Super::Jump();	
}

void AMyCharacter::Shoot()
{
	if (Weapon != nullptr)
	{
		Weapon->FireWeapon();
	}
}

void AMyCharacter::SetupWeapon()
{
	Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass);
	Weapon->AttachToComponent(FirstPersonCameraComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Weapon->SetOwner(this);
}

void AMyCharacter::UseAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("Used abilitiyt"))
	AbilityInventory->UseAbility();
}


//Testing time widget, move to level based timer.
void AMyCharacter::TimeTest()
{
	if(PlayerHUD)
	{
		TimerTime++;
		PlayerHUD->SetTime(TimerTime);
	}
}

void AMyCharacter::OnDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("DEATH FROM EVENT"))
}

void AMyCharacter::OnHealthChanged(int Health)
{
	
	if (HealthWidget)
	{
		GEngine->AddOnScreenDebugMessage(2, 15.0f, FColor::Yellow, TEXT("hit event happend"));
		UE_LOG(LogTemp, Warning, TEXT("%i"), Health);
		HealthWidget->UpdateHealth(Health);
	}
}


// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyCharacter::Jump);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &AMyCharacter::Shoot);
		EnhancedInputComponent->BindAction(AbilityAction, ETriggerEvent::Started, this, &AMyCharacter::UseAbility);
	}

}

