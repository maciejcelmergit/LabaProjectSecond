// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BarrelGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LABAPROJECTSECOND_API ABarrelGameMode : public AGameModeBase
{
	GENERATED_BODY()


	public:
		UFUNCTION(BlueprintCallable)
		void OnActorDeath(AActor* Actor);

		UFUNCTION(BlueprintPure)
		int GetDestroyedActors();

	private:
		int ActorsDestroyed = 0;
};
