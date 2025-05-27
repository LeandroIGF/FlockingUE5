// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidManager.generated.h"

class ABoid;

UCLASS()
class FLOCKING5_3_API ABoidManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	TArray<ABoid*> Boids;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float SeparationRadius = 200.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float AlignmentRadius = 400.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float CohesionRadius = 400.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float SeparationWeight = 200.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float AlignmentWeight = 200.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float CohesionWeight = 200.f;

	// Cube limit for boids
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	FVector BoundsCenter = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	FVector BoundsExtent = FVector(1000.f,1000.f,1000.f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BoidManager")
	float BoundsWeight = 2.f;
};
