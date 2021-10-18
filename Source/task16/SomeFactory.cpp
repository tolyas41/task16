// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeFactory.h"
#include "Unit.h"
#include "TimerManager.h"

// Sets default values
ASomeFactory::ASomeFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASomeFactory::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle MemberTimerHandle;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ASomeFactory::SpawnUnit, 2.0f, true, 2.0f);

}

// Called every frame
void ASomeFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASomeFactory::SpawnUnit()
{
	//GetWorld()->SpawnActor<AUnit>(UnitToSpawn, SpawnLocation, FRotator());
	GetWorld()->SpawnActor<AUnit>(UnitToSpawn, GetActorLocation(), FRotator());
}