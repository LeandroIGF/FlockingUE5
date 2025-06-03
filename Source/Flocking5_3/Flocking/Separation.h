// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Flocking5_3/FlockingRule.h"
#include "Separation.generated.h"

/**
 * 
 */
UCLASS()
class FLOCKING5_3_API USeparation : public UFlockingRule
{
	GENERATED_BODY()
public:
	
	
	virtual void NeighborCountVector(ABoid* Neighbor) override;
	virtual void FinalRuleVector(float RuleWeight) override;
};




