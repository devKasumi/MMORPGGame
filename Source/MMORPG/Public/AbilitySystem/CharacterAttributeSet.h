// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

class IPawnUIInterface;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class MMORPG_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UCharacterAttributeSet();

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, CurrentRage)

	UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxRage)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, AttackPower)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, DefensePower)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, DamageTaken)

private:
	TWeakInterfacePtr<IPawnUIInterface> CachedPawnUIInterface;

};
