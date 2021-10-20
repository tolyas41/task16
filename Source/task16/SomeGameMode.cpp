// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeGameMode.h"

void ASomeGameMode::BeginPlay()
{
	SuccessHits = 0;
	OnDamageEvent.AddUFunction(this, FName("HitSuccess"));
}

void ASomeGameMode::HitSuccess()
{
	SuccessHits++;
	UE_LOG(LogTemp, Warning, TEXT("Success Hits: %f"), SuccessHits);

}
