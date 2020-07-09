// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities\OCDamageExecution.h"
#include "Abilities\OCCharacterAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "..\..\Public\Abilities\OCDamageExecution.h"
#include "OCBaseCharacter.h"

struct DamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	DamageStatics()
	{
		// Also capture the source's raw Damage, which is normally passed in directly via the execution
		DEFINE_ATTRIBUTE_CAPTUREDEF(UOCCharacterAttributeSet, Damage, Source, true);
	}
};

static const DamageStatics& GetDamageStatics()
{
	static DamageStatics DmgStatics;
	return DmgStatics;
}

UOCDamageExecution::UOCDamageExecution()
	: DamageMulPerLvl(0.08)
{
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
}

void UOCDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	AOCBaseCharacter* SourceActor = SourceAbilitySystemComponent ? Cast<AOCBaseCharacter>(SourceAbilitySystemComponent->AvatarActor) : nullptr;
	AOCBaseCharacter* TargetActor = TargetAbilitySystemComponent ? Cast<AOCBaseCharacter>(TargetAbilitySystemComponent->AvatarActor) : nullptr;

	// Gather the tags from the source and target as that can affect which buffs should be used
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;
	

	float Damage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetDamageStatics().DamageDef, EvaluationParameters, Damage);

	float LvlBasedDmgMul = FMath::Clamp(DamageMulPerLvl * (SourceActor->GetCharacterLevel() - TargetActor->GetCharacterLevel()), -0.6f, 0.6f);
	float DamageDone = Damage + Damage * LvlBasedDmgMul;
	
	if (DamageDone > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Additive, DamageDone));
	}
}