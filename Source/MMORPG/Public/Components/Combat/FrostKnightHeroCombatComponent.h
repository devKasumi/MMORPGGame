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

	
};
