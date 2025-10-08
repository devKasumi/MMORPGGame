// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WeaponBase.h"

#include "DebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A Tag named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	//const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	//LOG_W(Debug::ConvertToStdString(WeaponString));
}

AWeaponBase* UPawnCombatComponent::GetCharcterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		//return CharacterCarriedWeaponMap[InWeaponTagToGet];
		if (AWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			//LOG_I("pokemon Found weapon for tag: {}", Debug::ConvertToStdString(InWeaponTagToGet.ToString()));
			return *FoundWeapon;
		}
	}

	//LOG_I("xDDDD No carried weapon found for tag: {}", Debug::ConvertToStdString(InWeaponTagToGet.ToString()));

	return nullptr;
}

AWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		//LOG_I("No currently equipped weapon tag is set");
		return nullptr;
	}
	//LOG_I("Getting currently equipped weapon for tag: {}", Debug::ConvertToStdString(CurrentEquippedWeaponTag.ToString()));
	return GetCharcterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
