// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Unit.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class IDamage;

UCLASS()
class TASK16_API AUnit : public AActor : public IDamage
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UStaticMeshComponent* StaticMeshComponent;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnDamage() override;

private:
	float Health{ 100 };
};
