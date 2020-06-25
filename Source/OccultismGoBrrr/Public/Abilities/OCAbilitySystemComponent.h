// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "OCAbilitySystemComponent.generated.h"

class UOCGameplayAbility;

/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UOCAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	UOCAbilitySystemComponent();

	/** Returns a list of currently active ability instances that match the tags */
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UOCGameplayAbility*>& ActiveAbilities);
	
	/** Version of function in AbilitySystemGlobals that returns correct type */
	static UOCAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);
};
