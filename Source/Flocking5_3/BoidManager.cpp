// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "Boid.h"
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
	BoundsCenter = GetActorLocation();
	
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

		//Calculate flocking for single boid
		FVector Separation = FVector::ZeroVector;
		FVector Alignment = FVector::ZeroVector;
		FVector Cohesion = FVector::ZeroVector;
		FVector Predator = FVector::ZeroVector;

		//Counting elements near us for alignment and cohesion calculation
		int32 AlignmentCount = 0;
		int32 CohesionCount = 0;
		int32 SeparationCount = 0;
		int32 PredatorCount = 0;

		FVector BoidLocation = Boid->GetActorLocation();

		//Calculate Flocking parameters for each of our neighbor
		for (ABoid* Neighbor : Boids)
		{
			if (!IsValid(Neighbor) || Neighbor == Boid || Neighbor->ActorHasTag(TEXT("Obstacle")) || Neighbor->ActorHasTag(TEXT("Predator"))) continue;

			float Dist = FVector::Distance(BoidLocation, Neighbor->GetActorLocation());

			if (Dist < SeparationRadius)
			{
				Separation += (Neighbor->GetActorLocation() - BoidLocation).GetSafeNormal();
				SeparationCount++;
			}

			if (Dist < AlignmentRadius)
			{
				Alignment += Neighbor->Velocity;
				AlignmentCount++;
			}

			if (Dist < CohesionRadius)
			{
				Cohesion += Neighbor->GetActorLocation();
				CohesionCount++;
			}

			if (Neighbor->ActorHasTag(TEXT("Predator")) && Dist < PredatorRadius)
			{
				Predator += (Neighbor->GetActorLocation() - BoidLocation).GetSafeNormal();
				PredatorCount++;
			}
		}			

		if (SeparationCount > 0)
		{
			Separation = ((Separation / SeparationCount) * -1.f).GetSafeNormal();
			//Separation /= SeparationCount;
			//Separation *= -1.f;
			//Separation.Normalize();
		}

		if (AlignmentCount > 0)
		{
			Alignment = (Alignment / AlignmentCount).GetSafeNormal();
		}

		if (CohesionCount > 0)
		{
			FVector AvgPos = Cohesion / CohesionCount;
			Cohesion = (AvgPos - BoidLocation).GetSafeNormal();
		}

		if (PredatorCount > 0)
		{
			Predator = ((Predator / PredatorCount) * -1.f).GetSafeNormal();
		}

		//Calculate direction when outside cube

		FVector BoundsMin = GetActorLocation() - BoundsExtent;
		FVector BoundsMax = GetActorLocation() + BoundsExtent;
		FVector BoundsForce = FVector::ZeroVector;

		if (BoidLocation.X < BoundsMin.X) BoundsForce.X = 1;
		else if (BoidLocation.X > BoundsMax.X) BoundsForce.X = -1;

		if (BoidLocation.Y < BoundsMin.Y) BoundsForce.Y = 1;
		else if (BoidLocation.Y > BoundsMax.Y) BoundsForce.Y = -1;

		if (BoidLocation.Z < BoundsMin.Z) BoundsForce.Z = 1;
		else if (BoidLocation.Z > BoundsMax.Z) BoundsForce.Z = -1;

		//Calculate weight
		//Final parameters values
		

		FFlockingInfo FlockingInfo;		
		
		if (Boid->bLeader)
		{
			FlockingInfo.Goal = (Boid->GoalLocation - Boid->GetActorLocation()).GetSafeNormal() * GoalWeight;
		}
		
		FlockingInfo.Bounds = BoundsForce.GetSafeNormal() * BoundsWeight;

		FlockingInfo.Separation = Separation * SeparationWeight;
		FlockingInfo.Alignment = Alignment * AlignmentWeight;
		FlockingInfo.Cohesion = Cohesion * CohesionWeight;
		FlockingInfo.Predator = Predator * PredatorWeight;

		//Update void
		//TODO: Put parameters inside a struct
		Boid->UpdateBoid(DeltaTime, FlockingInfo);
	}

}

