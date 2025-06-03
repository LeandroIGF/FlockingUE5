// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "FlockingRule.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

class UFlockingRule;
class UFlockingData;

USTRUCT(BlueprintType)
struct FFlockingInfo
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	float RuleRadius = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FlockingInfo")
	float RuleWeight = 1.f;	
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	TObjectPtr<UFlockingData> BoidFlockingData = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	TArray<TObjectPtr<UFlockingRule>> FlockingRuleList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	FVector BoundsExtent = FVector(2000.f,2000.f,2000.f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Boid")
	FVector Anchor = FVector::ZeroVector;

	UFUNCTION()
	void UpdateBoid(float DeltaTime);

};
