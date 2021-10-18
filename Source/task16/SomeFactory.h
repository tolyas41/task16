// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SomeFactory.generated.h"

class AUnit;


UCLASS()
class TASK16_API ASomeFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASomeFactory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AUnit> UnitToSpawn;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnLocation;


	UFUNCTION()
	void SpawnUnit();
};
