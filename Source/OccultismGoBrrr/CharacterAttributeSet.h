// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CharacterAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterAttributes")
	FGameplayAttributeData Health = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterAttributes")
	FGameplayAttributeData MaxHealth = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterAttributes")
	FGameplayAttributeData Mana = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterAttributes")
	FGameplayAttributeData MaxMana = 100;

};
