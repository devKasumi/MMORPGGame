// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "EnemyGameplayAbility.generated.h"

class AEnemyCharacter;
class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class MMORPG_API UEnemyGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	AEnemyCharacter* GetEnemyCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	FGameplayEffectSpecHandle MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat);

private:
	TWeakObjectPtr<AEnemyCharacter> CachedEnemyCharacter;


};
