// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeCharacter.h"
#include "Components/InputComponent.h"
#include "Projectile.h"

ASomeCharacter::ASomeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(RootComponent);

	bUseControllerRotationYaw = false;
}

void ASomeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASomeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//const FRotator NewRotation = GetActorRotation() + (CharRotation * RotateSpeed);
	//SetActorRotation(NewRotation);

}

void ASomeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Rotate", this, &ASomeCharacter::Rotate);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASomeCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASomeCharacter::MoveRight);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASomeCharacter::Fire);
}

void ASomeCharacter::Rotate(float Value)
{
	if (Value)
	{
		AddActorLocalRotation(FRotator(0, Value, 0));
	}
}

void ASomeCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ASomeCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void ASomeCharacter::Fire()
{
	if (ProjectileClass)
	{
		FVector SpawnLoc = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRot = ProjectileSpawnPoint->GetComponentRotation();
		AProjectile* ProjectileBullet = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLoc, SpawnRot);
	}

}

