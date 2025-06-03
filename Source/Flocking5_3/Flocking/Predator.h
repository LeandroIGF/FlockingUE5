// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Flocking5_3/FlockingRule.h"
#include "Predator.generated.h"

/**
 * 
 */
UCLASS()
class FLOCKING5_3_API UPredator : public UFlockingRule
{
	GENERATED_BODY()

	
	virtual void NeighborCountVector(ABoid* Neighbor) override;
	
	virtual void FinalRuleVector(float RuleWeight) override;
};
