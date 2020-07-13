// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "OCAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UOCAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:

	UOCAssetManager() {}

	/** Static types for items */
	static const FPrimaryAssetType PotionItemType;
	static const FPrimaryAssetType SkillItemType;
	static const FPrimaryAssetType TokenItemType;
	static const FPrimaryAssetType WeaponItemType;

	/** Returns the current AssetManager object */
	static UOCAssetManager& Get();
};
