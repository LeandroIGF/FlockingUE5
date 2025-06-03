// Fill out your copyright notice in the Description page of Project Settings.


#include "Separation.h"

#include "Flocking5_3/Boid.h"

void USeparation::NeighborCountVector(ABoid* Neighbor)
{
	Super::NeighborCountVector(Neighbor);
	RuleVector += (Neighbor->GetActorLocation() - Boid->GetActorLocation()).GetSafeNormal();
}

void USeparation::FinalRuleVector(float RuleWeight)
{
	RuleVector = ((RuleVector / RuleNeighbourCount) * -1.f).GetSafeNormal();
	RuleVector *= RuleWeight;
}
