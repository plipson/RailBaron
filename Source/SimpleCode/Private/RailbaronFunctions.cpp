// Fill out your copyright notice in the Description page of Project Settings.

#include "RailbaronFunctions.h"
#include "SimpleCode.h"

#ifdef SPUD_NON_META_WAY
FString URailbaronFunctions::GetCity(const FCityChoiceTable& Data, const FString& Region)
{
	//UE_LOG(RailBaron, Display, TEXT("-- looking up \"%s\""), *Region);
	if (Region.Equals(TEXT("NorthEast"), ESearchCase::IgnoreCase))
	{
		return Data.NorthEast;
	}
	if (Region.Equals(TEXT("SouthEast"), ESearchCase::IgnoreCase))
	{
		return Data.SouthEast;
	}
	if (Region.Equals(TEXT("NorthCentral"), ESearchCase::IgnoreCase))
	{
		return Data.NorthCentral;
	}
	if (Region.Equals(TEXT("SouthCentral"), ESearchCase::IgnoreCase))
	{
		return Data.SouthCentral;
	}
	if (Region.Equals(TEXT("Plains"), ESearchCase::IgnoreCase))
	{
		return Data.Plains;
	}
	if (Region.Equals(TEXT("NorthWest"), ESearchCase::IgnoreCase))
	{
		return Data.NorthWest;
	}
	if (Region.Equals(TEXT("SouthWest"), ESearchCase::IgnoreCase))
	{
		return Data.SouthWest;
	}

	return FString("ERROR");
}

FString URailbaronFunctions::Get(const FCityChoiceTable& Data, const FString& Field)
{
	FName FieldName(*Field);
	UStruct* ClassObj = FCityChoiceTable::StaticStruct();
	UProperty* Prop = ClassObj->FindPropertyByName(FieldName);
	const FString* ValuePtr = (Prop ? Prop->ContainerPtrToValuePtr<FString>(&Data) : nullptr);
	return (ValuePtr ? *ValuePtr : FString("Error"));
}
#endif

// WE allow field names to have spaces, which we'll squeeze out when creating their property name
template<class T>
FString GetStringValue(const T& Data, const FString& Field)
{
	FName FieldName(*(Field.Replace(TEXT(" "),TEXT(""))));
	UStruct* ClassObj = T::StaticStruct();
	UProperty* Prop = ClassObj->FindPropertyByName(FieldName);
	const FString* ValuePtr = (Prop ? Prop->ContainerPtrToValuePtr<FString>(&Data) : nullptr);
	return (ValuePtr ? *ValuePtr : FString("Error"));
}

FString URailbaronFunctions::GetCity(const FCityChoiceTable& Data, const FString& Region)
{
	return GetStringValue<FCityChoiceTable>(Data, Region);
}

FString URailbaronFunctions::GetPayout(const FCityPayouts& Data, const FString& City)
{
	return GetStringValue<FCityPayouts>(Data, City);
}

TArray<FString> URailbaronFunctions::GetCityList()
{
	return TArray<FString>
	{
		"Albany", "Atlanta", "Baltimore", "Billings", "Birmingham", "Boston", "Buffalo", "Butte", "Casper", "Charleston",
		"Charlotte", "Chattanooga", "Chicago", "Cincinnati", "Cleveland", "Columbus", "Dallas", "Denver", "Des Moines",
		"Detroit", "El Paso", "Fargo", "Fort Worth", "Houston", "Indianapolis", "Jacksonville", "Kansas City", "Knoxville",
		"Las Vegas", "Little Rock", "Los Angeles", "Louisville", "Memphis", "Miami", "Milwaukee", "Minneapolis", "Mobile",
		"Nashville", "New Orleans", "New York", "Norfolk", "Oakland", "Oklahoma City", "Omaha", "Philadelphia", "Phoenix",
		"Pittsburgh", "Pocatello", "Portland ME", "Portland OR", "Pueblo", "Rapid City", "Reno", "Richmond", "Sacramento",
		"Salt Lake City", "San Antonio", "San Diego", "San Francisco", "Seattle", "Shreveport", "Spokane", "St Louis",
		"St Paul", "Tampa", "Tucumcari", "Washington DC"
	};
}


