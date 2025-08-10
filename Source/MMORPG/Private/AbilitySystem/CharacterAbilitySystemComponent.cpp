// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CharacterAbilitySystemComponent.h"

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
