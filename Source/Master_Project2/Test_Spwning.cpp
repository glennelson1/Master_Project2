// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Spwning.h"

#include "GenericPlatform/GenericPlatformCrashContext.h"

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
	m_Height = 12;
	m_Width = 12;
	FHitResult HitResultDown, HitResultRight;
	FCollisionQueryParams CollisionParams;
	
	DeleteGrid();
	for(int Y = 0; Y <= m_Height; Y++)
	{
		for(int X = 0; X <= m_Width; X++)
		{
			FVector CellLocation = FVector(X * 100 , 0, Y * 100);
			//DrawDebugLine(GetWorld(),CellLocation,CellLocation + FVector(100, 0, 0), FColor::Orange, false, 10.0f );
			bool bHitDown = GetWorld()->LineTraceSingleByChannel(HitResultDown, CellLocation, CellLocation + FVector(0, 0, -100), ECC_Visibility, CollisionParams);
			bool bHitRight = GetWorld()->LineTraceSingleByChannel(HitResultRight, CellLocation, CellLocation + FVector(100, 0, 0), ECC_Visibility, CollisionParams);
			
			NeighbourDown = HitResultDown.GetActor();

			
			if(bHitDown)
			{
				if(HitResultDown.GetActor()->IsA(BlockType[0]) || HitResultDown.GetActor()->IsA(BlockType[1]) ||HitResultDown.GetActor()->IsA(BlockType[2]) ||HitResultDown.GetActor()->IsA(BlockType[3])||HitResultDown.GetActor()->IsA(BlockType[4])||HitResultDown.GetActor()->IsA(BlockType[4])||HitResultDown.GetActor()->IsA(BlockType[5]))
				{
					if(bHitRight)
					{
						if(!HitResultRight.GetActor()->IsA(BlockType[0]))
						{
							AActor* NewCell;
							NewCell = GetWorld()->SpawnActor<AActor>(GridSquare[0], CellLocation, FRotator::ZeroRotator);
							Cellref.Add(NewCell);
							SpawnElement(CellLocation);
						}
					}
					else
					{
						AActor* NewCell;
						NewCell = GetWorld()->SpawnActor<AActor>(GridSquare[0], CellLocation, FRotator::ZeroRotator);
						Cellref.Add(NewCell);
						SpawnElement(CellLocation);
					}

					
				}
				
			}
			
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

void ATest_Spwning::SpawnElement(FVector CellLocation)
{
	int32 RandomInt= FMath::RandRange(0, 100);
	
	//for (int i = 0; i < Cellref.Num(); i++)
	
		GetWorld()->SpawnActor<AActor>(Enemies[0], CellLocation, FRotator::ZeroRotator);
	
		//Delete enemies
	
}

// Called every frame
void ATest_Spwning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

