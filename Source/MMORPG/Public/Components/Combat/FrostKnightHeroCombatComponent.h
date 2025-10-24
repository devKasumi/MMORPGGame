// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "FrostKnightHeroCombatComponent.generated.h"

class AFrostKnightHeroWeapon;

/**
 * 
 */
UCLASS()
class MMORPG_API UFrostKnightHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FrostKnight|Combat")
	AFrostKnightHeroWeapon* GetFrostKnightHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "FrostKnight|Combat")
	AFrostKnightHeroWeapon* GetFrostKnightHeroCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "FrostKnight|Combat")
	float GetFrostKnightHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const;

	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor) override;

};
