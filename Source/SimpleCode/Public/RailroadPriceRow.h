#pragma once
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RailroadPriceRow.generated.h"

USTRUCT(BlueprintType)
struct FRailroadPriceRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//		FString ID;	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Cost;
};