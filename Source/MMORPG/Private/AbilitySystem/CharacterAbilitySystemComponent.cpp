// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "Items/Weapons/WarriorHeroWeapon.h"
#include "Items/Weapons/FrostKnightHeroWeapon.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "AbilitySystem/Abilities/FrostKnightHeroGameplayAbility.h"
//#include "GameFramework/Character.h"
//#include "Components/SkeletalMeshComponent.h"
//#include "Characters/FrostKnightHeroCharacter.h"
//#include "Components/PoseableMeshComponent.h"

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
		//FGameplayAbilitySpec AbilitySpec(TSubclassOf<UGameplayAbility>(AbilitySet.AbilityToGrant));
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

void UCharacterAbilitySystemComponent::GrantFrostKnightWeaponAbilities(const TArray<FFrostKnightHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if (InDefaultWeaponAbilities.IsEmpty()) return;

	for (const FFrostKnightHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		//FGameplayAbilitySpec AbilitySpec(TSubclassOf<UGameplayAbility>(AbilitySet.AbilityToGrant));
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UCharacterAbilitySystemComponent::RemoveGrantedFrostKnightWeaponAbilities(AFrostKnightHeroWeapon* FrostKnightHeroWeapon)
{
	TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles = FrostKnightHeroWeapon->GetGrantedAbilitySpecHandles();

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

bool UCharacterAbilitySystemComponent::TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate)
{
	check(AbilityTagToActivate.IsValid());

	TArray<FGameplayAbilitySpec*> FoundAbilitySpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(AbilityTagToActivate.GetSingleTagContainer(), FoundAbilitySpecs);

	if (!FoundAbilitySpecs.IsEmpty())
	{
		const int32 RandomAbilityIndex = FMath::RandRange(0, FoundAbilitySpecs.Num() - 1);
		FGameplayAbilitySpec* SpecToActivate = FoundAbilitySpecs[RandomAbilityIndex];

		check(SpecToActivate);

		if (!SpecToActivate->IsActive())
		{
			return TryActivateAbility(SpecToActivate->Handle);
		}
	}

	return false;
}
