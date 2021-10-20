// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeFactory.h"
#include "Unit.h"
#include "TimerManager.h"
#include "SomeGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SomeCharacter.h"

ASomeFactory::ASomeFactory()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASomeFactory::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle MemberTimerHandle;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ASomeFactory::SpawnUnit, 2.0f, true, 2.0f);

	//OnSpawnEvent.AddUFunction(this, FName("OnSpawn"));
	//OnSpawnEvent.AddUObject(this, &ASomeCharacter::Fire);
}

void ASomeFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASomeFactory::SpawnUnit()
{
	OnSpawnEvent.Broadcast();
	GetWorld()->SpawnActor<AUnit>(UnitToSpawn, GetActorLocation(), FRotator());
}

void ASomeFactory::OnSpawn()
{
	UE_LOG(LogTemp, Warning, TEXT("Unit Spawn!"));
}