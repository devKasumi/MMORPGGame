// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterTypes/CharacterStructTypes.h"
#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
