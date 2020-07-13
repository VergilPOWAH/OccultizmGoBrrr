// Fill out your copyright notice in the Description page of Project Settings.


#include "OCAssetManager.h"
#include "AbilitySystemGlobals.h"

const FPrimaryAssetType	UOCAssetManager::PotionItemType = TEXT("Potion");
const FPrimaryAssetType	UOCAssetManager::SkillItemType = TEXT("Skill");
const FPrimaryAssetType	UOCAssetManager::TokenItemType = TEXT("Token");
const FPrimaryAssetType	UOCAssetManager::WeaponItemType = TEXT("Weapon");

UOCAssetManager& UOCAssetManager::Get()
{
	UOCAssetManager* This = Cast<UOCAssetManager>(GEngine->AssetManager);

	if (This)
	{
		return *This;
	}
	else
	{
		//UE_LOG(LogOC, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be OCAssetManager!"));
		return *NewObject<UOCAssetManager>(); // never calls this
	}
}
