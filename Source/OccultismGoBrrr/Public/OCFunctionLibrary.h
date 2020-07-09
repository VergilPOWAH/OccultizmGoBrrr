// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OCTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayEffectTypes.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "OCFunctionLibrary.generated.h"
/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UOCFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/** Applies GameplayEffect spec that was made from an ability */
	UFUNCTION(BlueprintCallable, Category = Ability)
	static TArray<FActiveGameplayEffectHandle> ApplyExternalEffectContainerSpec(const TArray<FGameplayEffectSpecHandle>& GESpecHandles, const TArray<AActor*>& TargetActors);

	/** Returns true if count is greater than 0 */
	UFUNCTION(BlueprintCallable, Category = Item)
	static bool IsValid(const FOCItemData& ItemData);
};
