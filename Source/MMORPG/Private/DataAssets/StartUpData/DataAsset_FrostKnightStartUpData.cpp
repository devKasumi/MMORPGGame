// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_FrostKnightStartUpData.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"

void UDataAsset_FrostKnightStartUpData::GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	//Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	//for (const FFrostKnightHeroAbilitySet& AbilitySet : FrostKnightHeroStartUpAbilitySets)
	//{
	//	if (!AbilitySet.IsValid()) continue;

	//	FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
	//	//TSubclassOf<UGameplayAbility> AbilityClass = static_cast<TSubclassOf<UGameplayAbility>>(AbilitySet.AbilityToGrant);
	//	//FGameplayAbilitySpec AbilitySpec(AbilityClass);
	//	//TSubclassOf<UGameplayAbility> AbilityClass = AbilitySet.AbilityToGrant;
	//	//if (!AbilityClass) continue;

	//	//FGameplayAbilitySpec AbilitySpec(
	//	//	AbilityClass,
	//	//	ApplyLevel,
	//	//	INDEX_NONE,
	//	//	InASCToGive->GetAvatarActor()
	//	//);
	//	AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
	//	AbilitySpec.Level = ApplyLevel;
	//	AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

	//	InASCToGive->GiveAbility(AbilitySpec);
	//}
}
