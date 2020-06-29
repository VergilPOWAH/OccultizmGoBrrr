// Fill out your copyright notice in the Description page of Project Settings.


#include "OCBaseCharacter.h"
#include "AbilitySystemGlobals.h"
#include "Abilities/OCGameplayAbility.h"

// Sets default values
AOCBaseCharacter::AOCBaseCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UOCAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UOCCharacterAttributeSet>(TEXT("AttributeSet"));

	CharacterLevel = 1;
}

void AOCBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Initialize our abilities
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AddStartupGameplayAbilities();
	}
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

int32 AOCBaseCharacter::GetCharacterLevel() const
{
	return CharacterLevel;
}

bool AOCBaseCharacter::SetCharacterLevel(int32 NewLevel)
{
	if (CharacterLevel != NewLevel && NewLevel > 0)
	{
		// Our level changed so we need to refresh abilities
		RemoveStartupGameplayAbilities();
		CharacterLevel = NewLevel;
		AddStartupGameplayAbilities();

		return true;
	}
	return false;
}

UAbilitySystemComponent* AOCBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AOCBaseCharacter::AddStartupGameplayAbilities()
{
	check(AbilitySystemComponent);

	if (!bAbilitiesInitialized)
	{
		// Grant abilities, but only on the server	
		for (TSubclassOf<UOCGameplayAbility>& StartupAbility : GameplayAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, GetCharacterLevel(), INDEX_NONE, this));
		}

		// Now apply passives
		for (TSubclassOf<UGameplayEffect>& GameplayEffect : PassiveGameplayEffects)
		{
			FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
			EffectContext.AddSourceObject(this);

			FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, GetCharacterLevel(), EffectContext);
			if (NewHandle.IsValid())
			{
				FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent);
			}
		}
		bAbilitiesInitialized = true;
	}
}

void AOCBaseCharacter::RemoveStartupGameplayAbilities()
{
	check(AbilitySystemComponent);

	// Remove any abilities added from a previous call
	TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;
	for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if ((Spec.SourceObject == this) && GameplayAbilities.Contains(Spec.Ability->GetClass()))
		{
			AbilitiesToRemove.Add(Spec.Handle);
		}
	}

	// Do in two passes so the removal happens after we have the full list
	for (int32 i = 0; i < AbilitiesToRemove.Num(); i++)
	{
		AbilitySystemComponent->ClearAbility(AbilitiesToRemove[i]);
	}

	// Remove all of the passive gameplay effects that were applied by this character
	FGameplayEffectQuery Query;
	Query.EffectSource = this;
	AbilitySystemComponent->RemoveActiveEffects(Query);
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
