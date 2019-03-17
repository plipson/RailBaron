// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CityChoiceTable.h"
#include "CityPayouts.h"

#include "RailbaronFunctions.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLECODE_API URailbaronFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = RailBaron)
		static FString GetCity(const FCityChoiceTable& Data, const FString& Region);
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = RailBaron)
		static FString GetPayout(const FCityPayouts& Data, const FString& City);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = RailBaron)
		static TArray<FString> GetCityList();
};
