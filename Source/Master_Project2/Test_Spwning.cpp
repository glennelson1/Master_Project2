// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Spwning.h"

// Sets default values
ATest_Spwning::ATest_Spwning()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATest_Spwning::BeginPlay()
{
	
	m_Height = 5;
	m_Width = 50;
	Generation();
	Super::BeginPlay();
	
}

void ATest_Spwning::Generation()
{
	for(int Y = 0; Y <= m_Height; Y++)
	{
		for(int X = 0; X <= m_Width; X++)
		{
			FVector SpawnLocation = FVector(0, 0,0);
			GetWorld()->SpawnActor<AActor>(GridSquare[0], FVector(X * 100 , 0, Y * 100), FRotator::ZeroRotator);
			
		}
	}
}

// Called every frame
void ATest_Spwning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

