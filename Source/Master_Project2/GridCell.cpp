// Fill out your copyright notice in the Description page of Project Settings.


#include "GridCell.h"

// Sets default values
AGridCell::AGridCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AGridCell::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGridCell::Spawn(TSubclassOf<AActor> Element)
{
	int32 RandomInt= FMath::RandRange(0, 100);
	if(RandomInt <= 10)
	GetWorld()->SpawnActor<AActor>(Element, FVector(0, 0, 0), FRotator::ZeroRotator);
}

// Called every frame
void AGridCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

