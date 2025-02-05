// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "HasLineOfSight.generated.h"

/**
 * 
 */
UCLASS()
class LABAPROJECTSECOND_API UHasLineOfSight : public UBTDecorator
{
	GENERATED_BODY()

protected:

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetKey;
	
};
