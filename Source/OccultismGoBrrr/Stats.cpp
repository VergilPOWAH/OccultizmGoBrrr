// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats.h"



FAttributes UStats::SumAttributes(const FAttributes FirstsAttributes, const FAttributes SecondAttributes)
{
	TFieldIterator<UStructProperty> structIt1(FirstsAttributes.StaticStruct());
	TFieldIterator<UStructProperty> structIt2(SecondAttributes.StaticStruct());

	int32 nextStructShift = 0;

	for (; structIt1; ++structIt1, ++structIt2)
	{
		UStructProperty* structProperty1 = *structIt1;
		UStructProperty* structProperty2 = *structIt2;

		TFieldIterator<UFloatProperty> floatIt1(structProperty1->Struct);
		TFieldIterator<UFloatProperty> floatIt2(structProperty2->Struct);

		for (; floatIt1; ++floatIt1, ++floatIt2)
		{
			UFloatProperty* floatProperty1 = *floatIt1;
			UFloatProperty* floatProperty2 = *floatIt2;

			float* value1 = floatProperty1->GetPropertyValuePtr_InContainer((char*)&FirstsAttributes + nextStructShift);
			FString str = FString::SanitizeFloat(*value1);
			*value1 += *floatProperty2->GetPropertyValuePtr_InContainer((char*)&SecondAttributes + nextStructShift);
		}
		nextStructShift += structIt1->Struct->PropertiesSize;
	}
	return FirstsAttributes;
	//out = FirstsAttributes;
}
