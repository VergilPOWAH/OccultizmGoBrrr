// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OCTypes.h"
#include "Items/OCItem.h"
#include "Components/ActorComponent.h"
#include "OCInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OCCULTISMGOBRRR_API UOCInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOCInventoryComponent();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)

protected:
	int32 InventorySize = 256;
	TArray<FOCItemData> Items;

	/** Tries add one item stack to another. Returns what have left from AddingItemData after stacking */
	void TryStackItems(FOCItemData& TargetItemData, FOCItemData& AddingItemData);

	/** Looks for first invalid Item slot and fills it */
	bool AddItemToFirstFreeSlot(FOCItemData& AddingItemData);

public:
	/** Returns a copy of items in inventory */
	UFUNCTION(BlueprintCallable, Category = Inventory)
	const TArray<FOCItemData> GetInventoryItems() const;

	/** Adds item to inventory. Stack it if possible */
	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool AddInventoryItem(FOCItemData ItemData);
};
