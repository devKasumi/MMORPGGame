// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace HeroGameplayTags
{
	/** INput Tags **/
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_FrostKnight);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_FrostKnight);

	/** Warrior Player Tags **/
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Ability_Equip_Axe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Ability_Unequip_Axe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Ability_Attack_Light_Axe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Ability_Attack_Heavy_Axe);

	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Weapon_Axe);

	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Event_Equip_Axe);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Warrior_Event_Unequip_Axe);

	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	/** Frost Knight Tags **/
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrostKnight_Ability_Attack_Light);
	MMORPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FrostKnight_Ability_Attack_Heavy);
}
