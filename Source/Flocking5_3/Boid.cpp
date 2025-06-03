// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "Flocking/FlockingData.h"
#include "FlockingRule.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Velocity = GetActorForwardVector();

	
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(BoidFlockingData))
	{
		UE_LOG(LogTemp, Error, TEXT("BoidFlockingData is invalid"));
	}
	else
	{
		TArray<TSubclassOf<UFlockingRule>> Rules;
		BoidFlockingData->FlockingDataList.GetKeys(Rules);
		
		for (TSubclassOf<UFlockingRule> Rule : Rules)
		{
			UFlockingRule* RuleInstance = NewObject<UFlockingRule>(this, Rule);
			RuleInstance->Boid = this;
			FlockingRuleList.Add(RuleInstance);
		}
		
	}
	
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoid::UpdateBoid(float DeltaTime)
{

	FVector Direction;
	
	for (UFlockingRule* Rule :  FlockingRuleList)
	{
		UE_LOG(LogTemp, Warning, TEXT("Boid::UpdateBoid: Rule: %s"), *Rule->GetClass()->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Boid::UpdateBoid: Rule Value: %s"), *Rule->RuleVector.ToString());
		Direction += Rule->RuleVector;
	}
	
	Velocity = Velocity + Direction * DeltaTime;
	Velocity = Velocity.GetClampedToMaxSize(Speed);

	SetActorLocation(GetActorLocation() + Velocity * DeltaTime);

}

