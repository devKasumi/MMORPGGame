// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterTypes/CharacterStructTypes.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "AbilitySystem/Abilities/FrostKnightHeroGameplayAbility.h"
#include "AnimInstances/Hero/FrostKnightLinkedAnimLayer.h"
#include "AnimInstances/Hero/WarriorHeroLinkedAnimLayer.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

bool FFrostKnightHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
