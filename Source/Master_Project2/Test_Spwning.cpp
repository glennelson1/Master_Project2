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
	Super::BeginPlay();
}




void ATest_Spwning::SpawnGrid()
{
	m_Height = 5;
	m_Width = 10;
	DeleteGrid();
	for(int Y = 0; Y <= m_Height; Y++)
	{
		for(int X = 0; X <= m_Width; X++)
		{
			AActor* NewCell;
			NewCell = GetWorld()->SpawnActor<AActor>(GridSquare[0], FVector(X * 100 , 0, Y * 100), FRotator::ZeroRotator);
			Cellref.Add(NewCell);
		}
	}
}

void ATest_Spwning::DeleteGrid()
{
	for (AActor* actor : Cellref)
	{
		actor->Destroy();
		
	}
	Cellref.Empty();
}

// Called every frame
void ATest_Spwning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

