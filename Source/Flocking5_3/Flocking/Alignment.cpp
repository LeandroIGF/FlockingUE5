// Fill out your copyright notice in the Description page of Project Settings.


#include "Alignment.h"

void UAlignment::NeighborCountVector(ABoid* Neighbor)
{
	Super::NeighborCountVector(Neighbor);
	RuleVector += Neighbor->Velocity;	
}

void UAlignment::FinalRuleVector(float RuleWeight)
{
	RuleVector = (RuleVector / RuleNeighbourCount).GetSafeNormal();
	RuleVector *= RuleWeight;
}
