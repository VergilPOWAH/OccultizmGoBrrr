// Fill out your copyright notice in the Description page of Project Settings.


#include "OCFunctionLibrary.h"
#include "OCTypes.h"

bool UOCFunctionLibrary::IsValid(const FOCItemData& ItemData)
{
	return ItemData.ItemCount > 0;
}