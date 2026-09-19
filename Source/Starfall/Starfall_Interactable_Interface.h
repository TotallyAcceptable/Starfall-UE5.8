// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Starfall_Interactable_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UStarfall_Interactable_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFALL_API IStarfall_Interactable_Interface // Interface decleration
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interface")
	AActor* GetPlanet(); // Pure virtual function to get the planet actor
};
