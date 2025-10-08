// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/FrostKnightHeroCombatComponent.h"
#include "Items/Weapons/FrostKnightHeroWeapon.h"
#include "DebugHelper.h"

AFrostKnightHeroWeapon* UFrostKnightHeroCombatComponent::GetFrostKnightHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	AFrostKnightHeroWeapon* FrostKnightHeroWeapon = Cast<AFrostKnightHeroWeapon>(GetCharcterCarriedWeaponByTag(InWeaponTag));
	if (FrostKnightHeroWeapon)
	{
		//LOG_I("Found FrostKnightHeroWeapon for tag: {}", Debug::ConvertToStdString(InWeaponTag.ToString()));
		return FrostKnightHeroWeapon;
	}
	else
	{
		//LOG_I("No FrostKnightHeroWeapon found for tag: {}", Debug::ConvertToStdString(InWeaponTag.ToString()));
	}
	return nullptr;
}

