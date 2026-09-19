// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Starfall_PlanetActor.generated.h"

UCLASS()
class STARFALL_API AStarfall_PlanetActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStarfall_PlanetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
