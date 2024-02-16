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

	UPROPERTY(EditAnywhere, Category = "Test")
	TArray<AActor*> Block;
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<TSubclassOf<AActor>> GridSquare;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int m_Width;
	int m_Height;

	void Generation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
