// Fill out your copyright notice in the Description page of Project Settings.


#include "Predator.h"

void UPredator::NeighborCountVector(ABoid* Neighbor)
{
	
	if (Neighbor->ActorHasTag(TEXT("Predator")))
	{
		Super::NeighborCountVector(Neighbor);
		RuleVector += (Neighbor->GetActorLocation() - Boid->GetActorLocation()).GetSafeNormal();		
	}	
}

void UPredator::FinalRuleVector(float RuleWeight)
{
	RuleVector = ((RuleVector / RuleNeighbourCount) * -1.f).GetSafeNormal();
	RuleVector *= RuleWeight;
}
