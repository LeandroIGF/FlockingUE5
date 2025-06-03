// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockingBounds.h"

void UFlockingBounds::NeighborCountVector(ABoid* Neighbor)
{
	
}

void UFlockingBounds::FinalRuleVector(float RuleWeight)
{
	FVector BoundsMin = Boid->Anchor - Boid->BoundsExtent;
	FVector BoundsMax = Boid->Anchor + Boid->BoundsExtent;
	FVector BoundsForce = FVector::ZeroVector;

	if (Boid->Anchor.X < BoundsMin.X) BoundsForce.X = 1;
	else if (Boid->Anchor.X > BoundsMax.X) BoundsForce.X = -1;

	if (Boid->Anchor.Y < BoundsMin.Y) BoundsForce.Y = 1;
	else if (Boid->Anchor.Y > BoundsMax.Y) BoundsForce.Y = -1;

	if (Boid->Anchor.Z < BoundsMin.Z) BoundsForce.Z = 1;
	else if (Boid->Anchor.Z > BoundsMax.Z) BoundsForce.Z = -1;

	RuleVector = BoundsForce.GetSafeNormal() * RuleWeight;
}
