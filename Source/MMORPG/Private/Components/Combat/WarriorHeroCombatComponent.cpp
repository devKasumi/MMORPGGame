// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/WarriorHeroCombatComponent.h"
#include "Items/Weapons/WarriorHeroWeapon.h"

AWarriorHeroWeapon* UWarriorHeroCombatComponent::GetWarriorHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharcterCarriedWeaponByTag(InWeaponTag));
}
