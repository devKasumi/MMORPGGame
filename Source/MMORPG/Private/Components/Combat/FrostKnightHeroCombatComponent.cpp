// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/FrostKnightHeroCombatComponent.h"
#include "Items/Weapons/FrostKnightHeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "HeroGameplayTags.h"

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

AFrostKnightHeroWeapon* UFrostKnightHeroCombatComponent::GetFrostKnightHeroCurrentEquippedWeapon() const
{
	return Cast<AFrostKnightHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UFrostKnightHeroCombatComponent::GetFrostKnightHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetFrostKnightHeroCurrentEquippedWeapon()->FrostKnightHeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UFrostKnightHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		HeroGameplayTags::Shared_Event_MeleeHit,
		EventData
	);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		HeroGameplayTags::FrostKnight_Event_HitPause,
		EventData
	);
}

void UFrostKnightHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		HeroGameplayTags::FrostKnight_Event_HitPause,
		FGameplayEventData()
	);
}

