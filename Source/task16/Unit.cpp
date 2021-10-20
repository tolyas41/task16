// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Damage.h"
#include "Projectile.h"
#include "SomeCharacter.h"
#include "Kismet/GameplayStatics.h"

AUnit::AUnit()
{
	PrimaryActorTick.bCanEverTick = true;

	OnDamageEvent.AddUFunction(this, FName("OnDamage"));

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;
	BoxComponent->OnComponentHit.AddDynamic(this, &AUnit::OnDamage);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMeshComponent->SetupAttachment(BoxComponent);
}

void AUnit::BeginPlay()
{
	Super::BeginPlay();


}

void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health == 0)
	{
		Destroy();
		ASomeCharacter* CharInstance = Cast<ASomeCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ActorClass));
		CharInstance->OnHealEvent.Broadcast();
	}
}

//if projectile collides with unit -> OnDamageEvent
void AUnit::OnDamage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetClass() == ProjectileClass)
	{
		DamageToApply = FMath::Min(Health, DamageToApply);
		Health -= DamageToApply;
		UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);
	}
}
