// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/WeaponBase.h"
#include "CharacterTypes/CharacterStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "FrostKnightHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class MMORPG_API AFrostKnightHeroWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FFrostKnightHeroWeaponData FrostKnightHeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle>& GetGrantedAbilitySpecHandles();

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
	
};
