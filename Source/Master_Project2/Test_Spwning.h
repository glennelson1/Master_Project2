// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test_Spwning.generated.h"

UCLASS()
class MASTER_PROJECT2_API ATest_Spwning : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest_Spwning();

	
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<TSubclassOf<AActor>> GridSquare;

	UPROPERTY(EditAnywhere, Category = "Blocks")
	TArray<TSubclassOf<AActor>> BlockType;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	TArray<TSubclassOf<AActor>> Enemies;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int m_Width;
	int m_Height;
	int m_loc;

	TArray<AActor*> Cellref;
	
	UFUNCTION(BlueprintCallable)
	void SpawnGrid();
	UFUNCTION(BlueprintCallable)
	void DeleteGrid();
	
	AActor* NeighbourDown = nullptr;
	AActor* NeighbourRight = nullptr;
	UFUNCTION(BlueprintCallable)
	void SpawnElement();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
