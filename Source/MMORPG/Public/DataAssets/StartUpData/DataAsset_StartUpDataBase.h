// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UCharacterGameplayAbility;
class UCharacterAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class MMORPG_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UCharacterGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UCharacterGameplayAbility>> ReactiveAbilities;

	void GrandAbilities(const TArray<TSubclassOf<UCharacterGameplayAbility>>& InAbilitiesToGive, UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

};
