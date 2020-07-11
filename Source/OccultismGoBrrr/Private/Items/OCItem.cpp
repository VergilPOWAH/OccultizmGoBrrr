// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/OCItem.h"

bool UOCItem::IsConsumable() const
{
	if (MaxCount <= 0)
	{
		return true;
	}
	return false;
}

FPrimaryAssetId UOCItem::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType, GetFName());
}
