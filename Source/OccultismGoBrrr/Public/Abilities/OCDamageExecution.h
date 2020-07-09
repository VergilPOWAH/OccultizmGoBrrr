// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "OCDamageExecution.generated.h"

/**
 * 
 */
UCLASS()
class OCCULTISMGOBRRR_API UOCDamageExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

	UPROPERTY()
	float DamageMulPerLvl;

public:
	// Constructor and overrides
	UOCDamageExecution();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
