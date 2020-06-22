// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Stats.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FHealthStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float Health = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float MaxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float HealthRegenRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float ManaRegenRate;
};

USTRUCT(BlueprintType)
struct FDamageStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float DamageMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float DamageAdditition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float AbilityDamageMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float AbilityDamageAdditition;
};

USTRUCT(BlueprintType)
struct FResistStats
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float MagicalResist;
};


USTRUCT(BlueprintType)
struct FAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		FHealthStats HealthStats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		FDamageStats DamageStats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		FResistStats ResistStats;
};

UCLASS(Blueprintable, BlueprintType)
class OCCULTISMGOBRRR_API UStats : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Attribute")
		static FAttributes SumAttributes(const FAttributes FirstsAttributes, const FAttributes SecondAttributes);
	
};
