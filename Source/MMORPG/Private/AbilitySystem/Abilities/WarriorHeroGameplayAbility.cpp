// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/HeroController.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "HeroGameplayTags.h"

#include "DebugHelper.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedWarriorHeroCharacter.IsValid() ? CachedWarriorHeroCharacter.Get() : nullptr;
}

AHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedHeroCharacterController.IsValid())
	{
		CachedHeroCharacterController = Cast<AHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedHeroCharacterController.IsValid() ? CachedHeroCharacterController.Get() : nullptr;
}

UWarriorHeroCombatComponent* UWarriorHeroGameplayAbility::GetWarriorHeroCombatComponentFromActorInfo()
{
	if (GetHeroCharacterFromActorInfo()->GetWarriorCombatComponent())
	{
		//LOG_I("Found warrior hero combat component on character: {}", Debug::ConvertToStdString(GetHeroCharacterFromActorInfo()->GetName()));
		return GetHeroCharacterFromActorInfo()->GetWarriorCombatComponent();
	}
	else
	{
		//LOG_I("No warrior hero combat component found on character: {}", Debug::ConvertToStdString(GetHeroCharacterFromActorInfo()->GetName()));
	}
	return nullptr;
}

FGameplayEffectSpecHandle UWarriorHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
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

