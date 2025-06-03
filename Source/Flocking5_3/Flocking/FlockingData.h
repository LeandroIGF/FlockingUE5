// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Flocking5_3/FlockingRule.h"
#include "FlockingData.generated.h"

/**
 * 
 */
UCLASS()
class FLOCKING5_3_API UFlockingData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "FlockingData" )
	TMap<TSubclassOf<UFlockingRule>, FFlockingInfo> FlockingDataList;
	
};
