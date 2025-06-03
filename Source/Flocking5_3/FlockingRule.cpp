// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockingRule.h"

void UFlockingRule::NeighborCountVector(ABoid* Neighbor)
{
	// base implementation
	RuleNeighbourCount++;
}

void UFlockingRule::FinalRuleVector(float RuleWeight)
{
	// base implementation
	RuleVector = FVector::ZeroVector;
}
