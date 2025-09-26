// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/FrostKnightHeroGameplayAbility.h"
#include "Characters/FrostKnightHeroCharacter.h"
#include "Controllers/HeroController.h"

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