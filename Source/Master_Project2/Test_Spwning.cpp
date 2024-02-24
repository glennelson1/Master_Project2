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


void ATest_Spwning::Start()
{
	DeleteGrid();
	for(int i = 0; i <= 30; i += 10)
	{
		SpawnGrid(i);
	}
}

void ATest_Spwning::SpawnGrid(int num)
{
	
	m_Height = 12;
	m_Width = 10;
	m_EnityLastSection = 0;
	FHitResult HitResultDown, HitResultRight;
	FCollisionQueryParams CollisionParams;
	m_GridStart = 0;
	for(X = 1; X <= m_Width; X++)
	{
		m_GridStart = (X + num) * 100;
		//UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), m_GridStart);
		for(Y = 0; Y <= m_Height; Y++)
		{
			FVector CellLocation = FVector(m_GridStart, 0, Y * 100);
			
			//DrawDebugLine(GetWorld(),CellLocation,CellLocation + FVector(100, 0, 0), FColor::Orange, false, 10.0f );
			bool bHitDown = GetWorld()->LineTraceSingleByChannel(HitResultDown, CellLocation, CellLocation + FVector(0, 0, -100), ECC_Visibility, CollisionParams);
			bool bHitRight = GetWorld()->LineTraceSingleByChannel(HitResultRight, CellLocation, CellLocation + FVector(100, 0, 0), ECC_Visibility, CollisionParams);
			//UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *CellLocation.ToString());
			NeighbourDown = HitResultDown.GetActor();

			
			if(bHitDown)
				{
					if(HitResultDown.GetActor()->IsA(BlockType[0]) || HitResultDown.GetActor()->IsA(BlockType[1]) ||HitResultDown.GetActor()->IsA(BlockType[2]) ||HitResultDown.GetActor()->IsA(BlockType[3])||HitResultDown.GetActor()->IsA(BlockType[4])||HitResultDown.GetActor()->IsA(BlockType[4])||HitResultDown.GetActor()->IsA(BlockType[5]))
					{
						if(bHitRight)
						{
							if(!HitResultRight.GetActor()->IsA(BlockType[0]) &&!HitResultRight.GetActor()->IsA(BlockType[1]) && !HitResultRight.GetActor()->IsA(BlockType[2]) && !HitResultRight.GetActor()->IsA(BlockType[4]))
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
	m_EnityLastSection = 0;
	m_EnityLastSection = EnemyInSection.Num();
	UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), m_EnityLastSection);
	EnemyInSection.Empty();
}

void ATest_Spwning::DeleteGrid()
{
	for (AActor* actor : Cellref)
	{
		actor->Destroy();
		
	}
	for (AActor* actor : EnemyArray)
	{
		actor->Destroy();
		
	}
	Cellref.Empty();
}

void ATest_Spwning::SpawnElement(FVector CellLocation)
{
	int32 RandomInt= FMath::RandRange(0, 100);
	
	switch (m_Difficulty)
	{
	case 0:
		if(RandomInt <= 10)
		{
			AActor* NewCell;
			NewCell = GetWorld()->SpawnActor<AActor>(Enemies[0], CellLocation, FRotator::ZeroRotator);
			EnemyArray.Add(NewCell);
			EnemyInSection.Add(NewCell);
		}	
		break;
	case 1:
		if(RandomInt <= 15)
		{
			AActor* NewCell;
			NewCell = GetWorld()->SpawnActor<AActor>(Enemies[0], CellLocation, FRotator::ZeroRotator);
			EnemyArray.Add(NewCell);
			EnemyInSection.Add(NewCell);
		}	
		break;
	case 2:
		if(RandomInt <= 25)
		{
			AActor* NewCell;
			NewCell = GetWorld()->SpawnActor<AActor>(Enemies[0], CellLocation, FRotator::ZeroRotator);
			EnemyArray.Add(NewCell);
			EnemyInSection.Add(NewCell);
		}	
		break;
		default: break;
	}

	
	
	
}

// Called every frame
void ATest_Spwning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

