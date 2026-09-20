// Fill out your copyright notice in the Description page of Project Settings.
#include <iostream>
#include <ostream>

#include "Starfall_MainCharacter.h"

#include "EnhancedInputComponent.h"
#include "Starfall_PlanetActor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AStarfall_MainCharacter::AStarfall_MainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Planet = nullptr; // Initialize the planet reference to nullptr

}

void AStarfall_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
	
	
	UEnhancedInputComponent* Input =  Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!InputActions) return;
	
	Input->BindAction(InputActions->Move, ETriggerEvent::Triggered, this, &AStarfall_MainCharacter::Move);
	Input->BindAction(InputActions->Look, ETriggerEvent::Triggered, this, &AStarfall_MainCharacter::Look);
	Input->BindAction(InputActions->Jump, ETriggerEvent::Triggered, this, &AStarfall_MainCharacter::Jump);
}



// Called when the game starts or when spawned
void AStarfall_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Find and cache the planet actor in the world and assign it to the Planet reference
	TArray<AActor*> FoundActors; // Array to hold found actors of type AStarfall_PlanetActor
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStarfall_PlanetActor::StaticClass(), FoundActors); // Get all actors of type AStarfall_PlanetActor in the world
	if (FoundActors.Num() > 0) // Check if any actors were found
	{
		Planet = Cast<AStarfall_PlanetActor>(FoundActors[0]); // Cast the first found actor to AStarfall_PlanetActor and assign it to the Planet reference
	}

}

// Called every frame
void AStarfall_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update the gravity direction based on the planet's location
	FVector GravityDirection = Planet->GetActorLocation() - GetActorLocation(); // Calculate the direction vector from the character to the planet
	GravityDirection.Normalize(); // Normalize the direction vector to get a unit vector

	GetCharacterMovement()->SetGravityDirection(GravityDirection); // Set the gravity direction of the character's movement component to the calculated direction vector

}

AActor* AStarfall_MainCharacter::GetPlanet_Implementation()
{
	return Planet; // Return the cached planet reference
}

void AStarfall_MainCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FVector Forward = GetActorForwardVector();
		const FVector Right = GetActorRightVector();

		AddMovementInput(Forward, MovementVector.Y);
		AddMovementInput(Right, MovementVector.X);
	}
}

void AStarfall_MainCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

