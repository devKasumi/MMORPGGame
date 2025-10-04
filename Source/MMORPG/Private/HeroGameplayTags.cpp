// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroGameplayTags.h"

namespace HeroGameplayTags
{
	/** INput Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "InputTag.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe, "InputTag.UnequipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipSword, "InputTag.EquipSword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipSword, "InputTag.UnequipSword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe, "InputTag.LightAttack.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe, "InputTag.HeavyAttack.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_FrostKnight, "InputTag.LightAttack.FrostKnight");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_FrostKnight, "InputTag.HeavyAttack.FrostKnight");

	/** Warrior Hero Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Ability_Equip_Axe, "Warrior.Ability.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Ability_Unequip_Axe, "Warrior.Ability.Unequip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Ability_Attack_Light_Axe, "Warrior.Ability.Attack.Light.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Ability_Attack_Heavy_Axe, "Warrior.Ability.Attack.Heavy.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Warrior_Weapon_Axe, "Warrior.Weapon.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Warrior_Event_Equip_Axe, "Warrior.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Event_Unequip_Axe, "Warrior.Event.Unequip.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");

	/** Frost Knight Hero Tags **/
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Equip_Sword, "FrostKnight.Ability.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Unequip_Sword, "FrostKnight.Ability.Unequip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Attack_Light, "FrostKnight.Ability.Attack.Light");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Attack_Heavy, "FrostKnight.Ability.Attack.Heavy");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Weapon_Sword, "FrostKnight.Weapon.Sword");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Event_Equip_Sword, "FrostKnight.Event.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Event_Unequip_Sword, "FrostKnight.Event.Unequip.Sword");
}
