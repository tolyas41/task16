// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage.h"
#include "GameFramework/Character.h"
#include "SomeCharacter.generated.h"

class AProjectile;
class ASomeFactory;

DECLARE_EVENT(ASomeCharacter, FHealEvent)

UCLASS()
class TASK16_API ASomeCharacter : public ACharacter, public IDamage
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
	UFUNCTION()
	void Fire();
	UFUNCTION()
	virtual void OnDamage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullets")
		TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float MoveSpeed = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float RotateSpeed = 5.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "EventFactory")
	ASomeFactory* factory;

	UFUNCTION()
		void Heal(float HealAmount);

	FHealEvent OnHealEvent;

private:
	FRotator CharRotation;
	FVector MovementDirection;
	FVector CurrentVelocity;
	float Health{ 100 };
};
