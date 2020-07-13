// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/OCItem.h"
#include "OCSkillItem.generated.h"

/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UOCSkillItem : public UOCItem
{
	GENERATED_BODY()

public:
	UOCSkillItem()
	{
		ItemType = UOCAssetManager::SkillItemType;
	}

	
};
