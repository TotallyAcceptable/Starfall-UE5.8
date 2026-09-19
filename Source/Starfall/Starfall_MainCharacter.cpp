// Fill out your copyright notice in the Description page of Project Settings.


#include "Starfall_MainCharacter.h"

// Sets default values
AStarfall_MainCharacter::AStarfall_MainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Planet = nullptr; // Initialize the planet reference to nullptr

}

// Called when the game starts or when spawned
void AStarfall_MainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarfall_MainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStarfall_MainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

AActor* AStarfall_MainCharacter::GetPlanet_Implementation()
{
	return nullptr; // Return nullptr for now, you can implement logic to return the actual planet actor later
}

