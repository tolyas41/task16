// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SomeCharacter.generated.h"

class AProjectile;

UCLASS()
class TASK16_API ASomeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASomeCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Rotate(float Value);
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullets")
		TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
		float MoveSpeed = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
		float RotateSpeed = 5.0f;

private:
	FRotator CharRotation;
	FVector MovementDirection;
	FVector CurrentVelocity;

};
