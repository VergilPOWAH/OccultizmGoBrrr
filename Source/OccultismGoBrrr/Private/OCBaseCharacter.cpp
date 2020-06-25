// Fill out your copyright notice in the Description page of Project Settings.


#include "OCBaseCharacter.h"
#include "AbilitySystemGlobals.h"

// Sets default values
AOCBaseCharacter::AOCBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UOCAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

float AOCBaseCharacter::GetHealth() const
{
	if (!AttributeSet)
		return 1.f;

	return AttributeSet->GetHealth();
}

float AOCBaseCharacter::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float AOCBaseCharacter::GetMana() const
{
	return AttributeSet->GetMana();
}

float AOCBaseCharacter::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

float AOCBaseCharacter::GetMoveSpeed() const
{
	return AttributeSet->GetMoveSpeed();
}

UAbilitySystemComponent* AOCBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AOCBaseCharacter::HandleDamage(float DamageAmount, const FHitResult& HitInfo, const FGameplayTagContainer& DamageTags, AOCBaseCharacter* InstigatorCharacter, AActor* DamageCauser)
{
	OnDamaged(DamageAmount, HitInfo, DamageTags, InstigatorCharacter, DamageCauser);
}

void AOCBaseCharacter::HandleHealthChanged(float DeltaValue, const FGameplayTagContainer& EventTags)
{
	OnHealthChanged(DeltaValue, EventTags);
}

void AOCBaseCharacter::HandleManaChanged(float DeltaValue, const FGameplayTagContainer& EventTags)
{
	OnManaChanged(DeltaValue, EventTags);
}

void AOCBaseCharacter::HandleMoveSpeedChanged(float DeltaValue, const FGameplayTagContainer& EventTags)
{
	GetCharacterMovement()->MaxWalkSpeed = GetMoveSpeed();

	OnMoveSpeedChanged(DeltaValue, EventTags);
}
