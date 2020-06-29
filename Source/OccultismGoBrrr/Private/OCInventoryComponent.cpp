// Fill out your copyright notice in the Description page of Project Settings.


#include "OCInventoryComponent.h"

// Sets default values for this component's properties
UOCInventoryComponent::UOCInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Items.Empty();

	// Fills inventory with empty items
	for (int i = 0; i < InventorySize; i++)
	{
		Items.Add(FOCItemData());
	}
}

void UOCInventoryComponent::TryStackItems(FOCItemData& TargetItemData, FOCItemData& AddingItemData)
{
	int32 AvalibleSpace = TargetItemData.Item->MaxCount - TargetItemData.ItemCount;

	if (AddingItemData.ItemCount <= AvalibleSpace)
	{
		TargetItemData.ItemCount += AddingItemData.ItemCount;
		AddingItemData.ItemCount = 0;
	}
	else
	{
		TargetItemData.ItemCount += AvalibleSpace;
		AddingItemData.ItemCount -= AvalibleSpace;
	}
}

bool UOCInventoryComponent::AddItemToFirstFreeSlot(FOCItemData& AddingItemData)
{
	for (int i = 0; i < InventorySize; i++)
	{
		if (!Items[i].IsValid())
		{
			Items[i] = AddingItemData;
			return true;
		}
	}
	return false;
}

const TArray<FOCItemData> UOCInventoryComponent::GetInventoryItems() const
{
	return Items;
}

bool UOCInventoryComponent::AddInventoryItem(FOCItemData ItemData)
{
	if (!ItemData.Item || ItemData.ItemCount <= 0 || ItemData.ItemLevel <= 0)
	{
		return false;
	}

	if (ItemData.Item->MaxCount > 0)
	{
		FOCItemData* FoundedItem = Items.FindByPredicate([ItemData](FOCItemData ExistingItem) { return ExistingItem.Item == ItemData.Item &&
																																	  ExistingItem.Item->MaxCount > ExistingItem.ItemCount; });

		while (FoundedItem)
		{
			TryStackItems(*FoundedItem, ItemData);
			
			if (!ItemData.IsValid())
			{
				return true;
			}
			FoundedItem = Items.FindByPredicate([ItemData](FOCItemData ExistingItem) { return ExistingItem.Item == ItemData.Item &&
																														 ExistingItem.Item->MaxCount > ExistingItem.ItemCount; });
		}
	}

	//FString str = FString::FromInt(Items.GetAllocatedSize());
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, str);

	return AddItemToFirstFreeSlot(ItemData);
}
