// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "S_InputDataConfig.generated.h"

/**
 * 
 */
UCLASS()
class STARFALL_API US_InputDataConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Move;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Look;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Jump;
	
};
