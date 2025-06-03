// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
#include "Flocking/FlockingData.h"
// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	//BoundsCenter = GetActorLocation();

	for (ABoid* Boid : Boids)
	{
		Boid->Anchor = GetActorLocation();
	}
	
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Debug box bounds extent
	DrawDebugBox(GetWorld(), GetActorLocation(), BoundsExtent, FColor::Blue, false, -1, 0, 5);

	for (ABoid* Boid : Boids)
	{
		if (!IsValid(Boid)) continue;
		
		for (ABoid* Neighbor : Boids)
		{
			if (!IsValid(Neighbor) || Neighbor == Boid || Boid->ActorHasTag(TEXT("Obstacle")) || Boid->ActorHasTag(TEXT("Predator"))) continue;
			
			for (UFlockingRule* RuleCalculation :  Boid->FlockingRuleList)
			{
				//TODO: passare direttamente tutte le info?
				FFlockingInfo FlockingInfo = Boid->BoidFlockingData->FlockingDataList.FindRef(RuleCalculation->GetClass());
				RuleCalculation->NeighborCountVector(Neighbor);
			}
		}

		for (UFlockingRule* RuleCalculation :  Boid->FlockingRuleList)
		{
			//TODO: passare direttamente tutte le info?
			FFlockingInfo FlockingInfo = Boid->BoidFlockingData->FlockingDataList.FindRef(RuleCalculation->GetClass());
			//RuleCalculation->NeighborCountVector(Neighbor);
			RuleCalculation->FinalRuleVector(FlockingInfo.RuleWeight);
		}
		
		
		Boid->UpdateBoid(DeltaTime);
	}

}

