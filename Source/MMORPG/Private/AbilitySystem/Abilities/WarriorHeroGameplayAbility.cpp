// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/HeroController.h"
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
		LOG_I("Found warrior hero combat component on character: {}", Debug::ConvertToStdString(GetHeroCharacterFromActorInfo()->GetName()));
		return GetHeroCharacterFromActorInfo()->GetWarriorCombatComponent();
	}
	else
	{
		LOG_I("No warrior hero combat component found on character: {}", Debug::ConvertToStdString(GetHeroCharacterFromActorInfo()->GetName()));
	}
	return nullptr;
}

