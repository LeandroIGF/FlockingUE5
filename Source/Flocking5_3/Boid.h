// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

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

	UFUNCTION()
	void UpdateBoid(float DeltaTime, const FVector& Separation, const FVector& Alignment, const FVector& Cohesion, const FVector& Bounds);

};
