// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "FrostKnightHeroGameplayAbility.generated.h"

class AFrostKnightHeroCharacter;
class AHeroController;
class UFrotstKnightHeroCombatComponent;

/**
 * 
 */
UCLASS()
class MMORPG_API UFrostKnightHeroGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "FrostKnight|Ability")
	AFrostKnightHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "FrostKnight|Ability")
	AHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "FrostKnight|Ability")
	UFrostKnightHeroCombatComponent* GetFrostKnightHeroCombatComponentFromActorInfo();
	
private:
	TWeakObjectPtr<AFrostKnightHeroCharacter> CachedFrostKnightHeroCharacter;
	TWeakObjectPtr<AHeroController> CachedHeroCharacterController;
	
};
