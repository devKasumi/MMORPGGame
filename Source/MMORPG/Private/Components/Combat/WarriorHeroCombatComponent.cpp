// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/WarriorHeroCombatComponent.h"
#include "Items/Weapons/WarriorHeroWeapon.h"
#include "DebugHelper.h"

AWarriorHeroWeapon* UWarriorHeroCombatComponent::GetWarriorHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	AWarriorHeroWeapon* warriorHeroWeapon = Cast<AWarriorHeroWeapon>(GetCharcterCarriedWeaponByTag(InWeaponTag));
	if (warriorHeroWeapon)
	{
		LOG_I("Found warrior hero weapon for tag: {}", Debug::ConvertToStdString(InWeaponTag.ToString()));
		return warriorHeroWeapon;
	}
	else
	{
		LOG_I("chelsea cscscsc No warrior hero weapon found for tag: {}", Debug::ConvertToStdString(InWeaponTag.ToString()));
	}
	return nullptr;
}
