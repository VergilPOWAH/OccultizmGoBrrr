// Fill out your copyright notice in the Description page of Project Settings.


#include "OCFunctionLibrary.h"
#include "OCTypes.h"

TArray<FActiveGameplayEffectHandle> UOCFunctionLibrary::ApplyExternalEffectContainerSpec(const TArray<FGameplayEffectSpecHandle>& GESpecHandles, const TArray<AActor*>& TargetActors)
{
	TArray<FActiveGameplayEffectHandle> AllEffects;

	if (TargetActors.Num() > 0)
	{
		FGameplayAbilityTargetData_ActorArray* TargetData = new FGameplayAbilityTargetData_ActorArray();
		TargetData->TargetActorArray.Append(TargetActors);
		
		for (const FGameplayEffectSpecHandle& SpecHandle : GESpecHandles)
		{
			if (SpecHandle.IsValid())
			{
				AllEffects.Append(TargetData->ApplyGameplayEffectSpec(*SpecHandle.Data));
			}
		}
	}
	return AllEffects;
}

bool UOCFunctionLibrary::IsValid(const FOCItemData& ItemData)
{
	return ItemData.ItemCount > 0;
}