// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/PrimaryAssetId.h"
#include "OCTypes.generated.h"

class UOCItem;

/**
 * 
 */
USTRUCT(BlueprintType)
struct OCCULTISMGOBRRR_API FOCItemSlot
{
	GENERATED_BODY()

	/** Constructor, -1 means an invalid slot */
	FOCItemSlot()
		: SlotNumber(-1)
	{}

	FOCItemSlot(const FPrimaryAssetType& InItemType, int32 InSlotNumber)
		: ItemType(InItemType)
		, SlotNumber(InSlotNumber)
	{}

	/** The type of items that can go in this slot */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FPrimaryAssetType ItemType;

	/** The number of this slot, 0 indexed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 SlotNumber;

	/** Equality operators */
	/*bool operator==(const FRPGItemSlot& Other) const
	{
		return ItemType == Other.ItemType && SlotNumber == Other.SlotNumber;
	}
	bool operator!=(const FRPGItemSlot& Other) const
	{
		return !(*this == Other);
	}*/
};

/** Extra information about a URPGItem that is in a player's inventory */
USTRUCT(BlueprintType)
struct OCCULTISMGOBRRR_API FOCItemData
{
	GENERATED_BODY()

	/** Constructs, empty Item */
	FOCItemData()
		: Item(nullptr)
		, ItemCount(-1)
		, ItemLevel(-1)
	{}

	FOCItemData(UOCItem* Item,int32 InItemCount, int32 InItemLevel)
		: Item(Item)
		, ItemCount(InItemCount)
		, ItemLevel(InItemLevel)
	{}

	/** The number of instances of this item in the inventory, can never be below 1 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	UOCItem* Item;

	/** The number of instances of this item in the inventory, can never be below 1 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 ItemCount;

	/** The level of this item. This level is shared for all instances, can never be below 1 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 ItemLevel;

	//** Equality operators */
	//bool operator==(const FRPGItemData& Other) const
	//{
	//	return ItemCount == Other.ItemCount && ItemLevel == Other.ItemLevel;
	//}
	//bool operator!=(const FRPGItemData& Other) const
	//{
	//	return !(*this == Other);
	//}

	/** Returns true if count is greater than 0 */
	bool IsValid() const
	{
		return ItemCount > 0;
	}

	//** Append an item data, this adds the count and overrides everything else */
	//void UpdateItemData(const FRPGItemData& Other, int32 MaxCount, int32 MaxLevel)
	//{
	//	if (MaxCount <= 0)
	//	{
	//		MaxCount = MAX_int32;
	//	}

	//	if (MaxLevel <= 0)
	//	{
	//		MaxLevel = MAX_int32;
	//	}

	//	ItemCount = FMath::Clamp(ItemCount + Other.ItemCount, 1, MaxCount);
	//	ItemLevel = FMath::Clamp(Other.ItemLevel, 1, MaxLevel);
	//}
};
