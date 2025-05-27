// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

USTRUCT(BlueprintType)
struct FFlockingInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	FVector Separation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	FVector Alignment = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	FVector Cohesion = FVector::ZeroVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	FVector Bounds = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	FVector Goal = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	FVector Predator = FVector::ZeroVector;

	FVector ComputeTotalForce() const
	{
		return Separation + Alignment + Cohesion + Bounds + Goal + Predator;
	}
};



UCLASS()
class FLOCKING5_3_API ABoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	float Speed = 100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	FVector Velocity = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	bool bLeader = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	FVector GoalLocation = FVector::ZeroVector;

	UFUNCTION()
	void UpdateBoid(float DeltaTime, const FFlockingInfo& FlockingInfo);

};
