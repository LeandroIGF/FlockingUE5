// Fill out your copyright notice in the Description page of Project Settings.


#include "Cohesion.h"

void UCohesion::NeighborCountVector(ABoid* Neighbor)
{
	Super::NeighborCountVector(Neighbor);
	RuleVector += Neighbor->GetActorLocation();
}

void UCohesion::FinalRuleVector(float RuleWeight)
{
	FVector AvgPos = RuleVector / RuleNeighbourCount;
	RuleVector = (AvgPos - Boid->GetActorLocation()).GetSafeNormal();
	RuleVector *= RuleWeight;
}
