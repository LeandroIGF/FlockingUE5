// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boid.h"
#include "UObject/NoExportTypes.h"
#include "FlockingRule.generated.h"

class ABoid;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FLOCKING5_3_API UFlockingRule : public UObject
{
	GENERATED_BODY()
public:
	// Flocking Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
    FVector RuleVector = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	int32 RuleNeighbourCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	TObjectPtr<ABoid> Boid = nullptr;

	// Calculate Flocking Functions
	UFUNCTION()
	virtual void NeighborCountVector(ABoid* Neighbor);

	UFUNCTION()
	virtual void FinalRuleVector(float RuleWeight);
};
