// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Starfall_Interactable_Interface.h"
#include "Starfall_PlayerController.h"
#include "S_InputDataConfig.h"
#include "Starfall_MainCharacter.generated.h"

class UInputMappingContext;
class US_InputDataConfig;

UCLASS()
class STARFALL_API AStarfall_MainCharacter : public ACharacter, public IStarfall_Interactable_Interface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStarfall_MainCharacter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planet")
	AActor* Planet; // Reference to the planet actor the player is on
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Direction")
	FVector downDirection;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	UInputMappingContext* InputMapping;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	US_InputDataConfig* InputActions;
	
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	
	UFUNCTION()
	void Look(const FInputActionValue& Value);

private:

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// Implementation of the interface function to get the planet actor
	virtual AActor* GetPlanet_Implementation() override;
	
};
