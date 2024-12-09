// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorComponentCode.h"

// Sets default values for this component's properties
URotatorComponentCode::URotatorComponentCode()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatorComponentCode::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotatorComponentCode::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AActor* Owner = GetOwner())
	{
		FRotator rotation = FRotator::ZeroRotator;
		rotation.Yaw = RotateSpeedZ * DeltaTime;
		rotation.Roll = RotateSpeedX * DeltaTime;
		rotation.Pitch = RotateSpeedY * DeltaTime;


		Owner->AddActorLocalRotation(rotation);
	}
}

