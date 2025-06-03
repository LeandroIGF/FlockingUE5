// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"

void UGoal::NeighborCountVector(ABoid* Neighbor)
{
	
}

void UGoal::FinalRuleVector(float RuleWeight)
{
	//TODO: Change so every boid can go towards a goal Location
	if (Boid->bLeader)
	{
		RuleVector = (Boid->GoalLocation - Boid->GetActorLocation()).GetSafeNormal();
		RuleVector *= RuleWeight;
	}
	else
	{
		Super::FinalRuleVector(RuleWeight);
	}
	
}
