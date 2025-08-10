// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/HeroController.h"

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
	return GetHeroCharacterFromActorInfo()->GetWarriorCombatComponent();
}
