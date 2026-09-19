// Fill out your copyright notice in the Description page of Project Settings.


#include "Starfall_PlanetActor.h"


// Sets default values
AStarfall_PlanetActor::AStarfall_PlanetActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStarfall_PlanetActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarfall_PlanetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

