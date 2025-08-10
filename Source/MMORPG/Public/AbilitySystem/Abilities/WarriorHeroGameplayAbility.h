// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorHeroCharacter;
class AWarriorHeroController;

/**
 * 
 */
UCLASS()
class MMORPG_API UWarriorHeroGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();

	//UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	//AWarriorHeroController* GetWarriorHeroController


private:
	TWeakObjectPtr<AWarriorHeroCharacter> CachedWarriorHeroCharacter;


};
