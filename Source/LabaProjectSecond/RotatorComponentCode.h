// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "RotatorComponentCode.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABAPROJECTSECOND_API URotatorComponentCode : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotatorComponentCode();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	UPROPERTY(EditAnywhere)
	float RotateSpeedX = 0.0f;

	UPROPERTY(EditAnywhere)
	float RotateSpeedY = 0.0f;

	UPROPERTY(EditAnywhere)
	float RotateSpeedZ = 0.0f;
};
