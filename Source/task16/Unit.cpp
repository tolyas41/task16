// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Damage.h"

// Sets default values
AUnit::AUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMeshComponent->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Health == 0)
	{
		Destroy();
	}
}

void AUnit::OnDamage()
{
	TakeDamage()
}

//void ReceiveAnyDamage(float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);


/**
 * Apply damage to this actor.
 * @see https://www.unrealengine.com/blog/damage-in-ue4
 * @param DamageAmount		How much damage to apply
 * @param DamageEvent		Data package that fully describes the damage received.
 * @param EventInstigator	The Controller responsible for the damage.
 * @param DamageCauser		The Actor that directly caused the damage (e.g. the projectile that exploded, the rock that landed on you)
 * @return					The amount of damage actually applied.
 */
float AUnit::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);

	return DamageAmount;
}
