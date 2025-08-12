// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "Items/Weapons/WarriorHeroWeapon.h"

void UCharacterAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UCharacterAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{

}

void UCharacterAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if (InDefaultWeaponAbilities.IsEmpty()) return;

	for (const FWarriorHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UCharacterAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(AWarriorHeroWeapon* WarriorHeroWeapon)
{
	TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles = WarriorHeroWeapon->GetGrantedAbilitySpecHandles();

	if (GrantedAbilitySpecHandles.IsEmpty()) return;

	for (auto&& SpecHandle : GrantedAbilitySpecHandles)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}

	GrantedAbilitySpecHandles.Empty();
}
