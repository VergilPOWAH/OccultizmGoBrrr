// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/OCItem.h"
#include "OCWeaponItem.generated.h"

/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UOCWeaponItem : public UOCItem
{
	GENERATED_BODY()

public:
	UOCWeaponItem()
	{
		ItemType = UOCAssetManager::WeaponItemType;
	}	

	/** Weapon actor to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon)
	TSubclassOf<AActor> WeaponActor;
};
