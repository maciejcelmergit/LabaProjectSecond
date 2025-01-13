// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabberComponent.h"

// Sets default values for this component's properties
UGrabberComponent::UGrabberComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberComponent::BeginPlay()
{
	Super::BeginPlay();
	
	m_inputComponent = GetOwner()->GetComponentByClass<UInputComponent>();

	if (m_inputComponent)
	{
		m_inputComponent->BindAction("Use", IE_Pressed, this, &UGrabberComponent::Use);
		m_inputComponent->BindAction("Throw", IE_Pressed, this, &UGrabberComponent::Throw);
	}

	m_physicsHandle = GetOwner()->GetComponentByClass<UPhysicsHandleComponent>();
}


// Called every frame
void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (m_physicsHandle && m_physicsHandle->GetGrabbedComponent())
	{
		FVector TraceStart;
		FVector TraceEnd;
		FRotator CameraRotation;

		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(TraceStart, CameraRotation);
		TraceEnd = TraceStart + CameraRotation.Vector() * GrabRange;

		m_physicsHandle->SetTargetLocationAndRotation(TraceEnd, CameraRotation);
	}
}

void UGrabberComponent::Use()
{
	// jezeli trzyamm obiekt
	if (m_physicsHandle && m_physicsHandle->GetGrabbedComponent())
	{
		// upuszczam
		Release();
	}
	else 	// jezeli nie trzymam 
	{
		// to chwytam
		Grab();
	}
}

void UGrabberComponent::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab!"));

	FVector TraceStart;
	FVector TraceEnd;
	FRotator CameraRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(TraceStart, CameraRotation);

	TraceEnd = TraceStart + CameraRotation.Vector() * GrabRange;

	FHitResult HitRes;

	GetWorld()->LineTraceSingleByChannel(HitRes, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

	// DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor(0, 0, 255), false, 5, 0 , 5.0f);

	if (m_physicsHandle && HitRes.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Found object: %s"), *HitRes.GetActor()->GetName());

		m_physicsHandle->GrabComponentAtLocationWithRotation(HitRes.GetComponent(), FName(), HitRes.GetComponent()->GetComponentLocation(), HitRes.GetComponent()->GetComponentRotation());
	}
}

void UGrabberComponent::Release()
{
	if (m_physicsHandle)
	{
		m_physicsHandle->ReleaseComponent();
	}
}

void UGrabberComponent::Throw()
{
	if (m_physicsHandle && m_physicsHandle->GetGrabbedComponent())
	{
		UPrimitiveComponent* Component = m_physicsHandle->GetGrabbedComponent();
		m_physicsHandle->ReleaseComponent();

		FVector TraceStart;
		FRotator CameraRotation;

		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(TraceStart, CameraRotation);

		Component->AddImpulse(CameraRotation.Vector() * ThrowStrength, FName(), true);
	}
}

FString UGrabberComponent::GetGrabbedActorName()
{
	if (m_physicsHandle && m_physicsHandle->GetGrabbedComponent())
	{
		return m_physicsHandle->GetGrabbedComponent()->GetOwner()->GetActorNameOrLabel();


		//return AActor::GetDebugName(m_physicsHandle->GetGrabbedComponent()->GetOwner());
	}
	
	return FString();
}

