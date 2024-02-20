// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCG_LEVEL_GEN.generated.h"

UCLASS()
class MASTER_PROJECT2_API APCG_LEVEL_GEN : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APCG_LEVEL_GEN();

protected:
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<TSubclassOf<AActor>> CellClasses;
	
	
	TArray<AActor*> Cellref;
	
	UFUNCTION(BlueprintCallable)
	void DeleteGrid();
	
	UFUNCTION(BlueprintCallable)
	void SpawnGrid();
	
	int m_LastCellPos;

	//Level elements
	void SpawnFloor(int loc);
	void SpawnBricks(int loc);
	void SpawnOb(int loc);
	void SpawnPlatforms(int loc);

	
	FString GenerateSeed();
	
	void SaveSeedToFile(const FString& Seed);
	void DebugPrintSeed();
	

	UPROPERTY(EditAnywhere, Category = "Seed")
	TArray<int32> RandomChoices;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
