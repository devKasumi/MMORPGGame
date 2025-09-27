// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/FrostKnightHeroWeapon.h"

void AFrostKnightHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle>& AFrostKnightHeroWeapon::GetGrantedAbilitySpecHandles()
{
	return GrantedAbilitySpecHandles;
}

