// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/FrostKnightHeroGameplayAbility.h"
#include "Characters/FrostKnightHeroCharacter.h"
#include "Controllers/HeroController.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "HeroGameplayTags.h"

#include "DebugHelper.h"

AFrostKnightHeroCharacter* UFrostKnightHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedFrostKnightHeroCharacter.IsValid())
	{
		CachedFrostKnightHeroCharacter = Cast<AFrostKnightHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedFrostKnightHeroCharacter.IsValid() ? CachedFrostKnightHeroCharacter.Get() : nullptr;
}

AHeroController* UFrostKnightHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedHeroCharacterController.IsValid())
	{
		CachedHeroCharacterController = Cast<AHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedHeroCharacterController.IsValid() ? CachedHeroCharacterController.Get() : nullptr;
}

UFrostKnightHeroCombatComponent* UFrostKnightHeroGameplayAbility::GetFrostKnightHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetFrostKnightCombatComponent();
}

FGameplayEffectSpecHandle UFrostKnightHeroGameplayAbility::MakeFrostKnightDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetCharacterAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetCharacterAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(
		HeroGameplayTags::Shared_SetByCaller_BaseDamage,
		InWeaponBaseDamage
	);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(
			InCurrentAttackTypeTag,
			InUsedComboCount
		);
	}

	return EffectSpecHandle;

}
