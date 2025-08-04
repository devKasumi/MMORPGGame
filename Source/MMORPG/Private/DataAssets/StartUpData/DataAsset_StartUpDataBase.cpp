// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrandAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrandAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrandAbilities(const TArray<TSubclassOf<UCharacterGameplayAbility>>& InAbilitiesToGive, UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UCharacterGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
