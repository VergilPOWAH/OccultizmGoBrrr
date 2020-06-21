// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats.h"



void UStats::SumAttributes(const FAttributes FirstsAttributes, const FAttributes SecondAttributes, FAttributes& out)
{
	//UStruct* object = Cast<UStruct, FAttributes>(&FirstsAttributes);
	float x = 0;

	
	//TFieldIterator<UStructProperty> It2((UStruct*)&SecondAttributes);
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
			/*float* value1 = floatProperty1->GetPropertyValuePtr_InContainer(structProperty1->Struct);
			*value1 += *floatProperty2->GetPropertyValuePtr_InContainer(structProperty2->Struct);
			*/
			//floatProperty1->SetFloatingPointPropertyValue((UObject*)structProperty1->Struct, *value1);
			//i++;
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, str);			
		}
		nextStructShift += structIt1->Struct->PropertiesSize;
	}
		//UFloatProperty* Property1 = *It1;
		//UFloatProperty* Property2 = *It2;
		//
		//float* value1 = Property1->GetPropertyValuePtr_InContainer((UObject*)&FirstsAttributes);
		//*value1 += *Property2->GetPropertyValuePtr_InContainer((UObject*)&SecondAttributes);
		//FString str = FString::SanitizeFloat(*value1 );
		//Property1->SetFloatingPointPropertyValue((UObject*)&FirstsAttributes, *value1 + *value2);




		//FString str = FString::FromInt(x);
		//#if UE_BUILD_DEBUG
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, str);
		//#endif

	out = FirstsAttributes;
}
