// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelGameMode.h"

void ABarrelGameMode::OnActorDeath(AActor* Actor)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor destoyed: %s"), *Actor->GetName());

	ActorsDestroyed++;

}


int ABarrelGameMode::GetDestroyedActors()
{
	return ActorsDestroyed;
}