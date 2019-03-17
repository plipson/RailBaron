// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CityChoiceTable.generated.h"

// , REGION, NorthEast, SouthEast, NorthCentral, SouthCentral, Plains, NorthWest, SouthWest
// 2, NorthCentral, Baltimore, Norfolk, Cleveland, Nashville, Denver, Salt Lake City, Phoenix

USTRUCT(BlueprintType)
struct FCityChoiceTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//		FString DieRoll;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Region;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString NorthEast;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString SouthEast;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString NorthCentral;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString SouthCentral;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Plains;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString NorthWest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString SouthWest;
};


