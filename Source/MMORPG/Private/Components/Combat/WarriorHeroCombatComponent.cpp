// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/WarriorHeroCombatComponent.h"
#include "Items/Weapons/WarriorHeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "HeroGameplayTags.h"

#include "DebugHelper.h"

AWarriorHeroWeapon* UWarriorHeroCombatComponent::GetWarriorHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	AWarriorHeroWeapon* warriorHeroWeapon = Cast<AWarriorHeroWeapon>(GetCharcterCarriedWeaponByTag(InWeaponTag));
	if (warriorHeroWeapon)
	{
		//LOG_I("Found warrior hero weapon for tag: {}", Debug::ConvertToStdString(InWeaponTag.ToString()));
		return warriorHeroWeapon;
	}
	else
	{
		//LOG_I("chelsea cscscsc No warrior hero weapon found for tag: {}", Debug::ConvertToStdString(InWeaponTag.ToString()));
	}
	return nullptr;
}

AWarriorHeroWeapon* UWarriorHeroCombatComponent::GetWarriorHeroCurrentEquippedWeapon() const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UWarriorHeroCombatComponent::GetWarriorHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetWarriorHeroCurrentEquippedWeapon()->WarriorHeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UWarriorHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	//LOG_I(FColor::Blue, "{} hit {}", GetOwningPawn()->GetActorNameOrLabel(), HitActor->GetActorNameOrLabel());
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
		HeroGameplayTags::Warrior_Event_HitPause,
		FGameplayEventData()
	);
}

void UWarriorHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	//LOG_I(FColor::Green, "{}'s weapon pulled from {}", GetOwningPawn()->GetActorNameOrLabel(), InteractedActor->GetActorNameOrLabel());
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		HeroGameplayTags::Warrior_Event_HitPause,
		FGameplayEventData()
	);
}
