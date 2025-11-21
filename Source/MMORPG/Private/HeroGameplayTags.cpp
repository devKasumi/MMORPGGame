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

	UE_DEFINE_GAMEPLAY_TAG(Warrior_Ability_HitPause, "Warrior.Ability.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(Warrior_Weapon_Axe, "Warrior.Weapon.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Warrior_Event_Equip_Axe, "Warrior.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Event_Unequip_Axe, "Warrior.Event.Unequip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_Event_HitPause, "Warrior.Event.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(Warrior_SetByCaller_AttackType_Light, "Warrior.SetByCaller.AttackType.Light");
	UE_DEFINE_GAMEPLAY_TAG(Warrior_SetByCaller_AttackType_Heavy, "Warrior.SetByCaller.AttackType.Heavy");

	/** Frost Knight Hero Tags **/
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Equip_Sword, "FrostKnight.Ability.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Unequip_Sword, "FrostKnight.Ability.Unequip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Attack_Light, "FrostKnight.Ability.Attack.Light");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_Attack_Heavy, "FrostKnight.Ability.Attack.Heavy");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Ability_HitPause, "FrostKnight.Ability.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Weapon_Sword, "FrostKnight.Weapon.Sword");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Event_Equip_Sword, "FrostKnight.Event.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Event_Unequip_Sword, "FrostKnight.Event.Unequip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Event_Scale_Sword, "FrostKnight.Event.Scale.Sword");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_Event_HitPause, "FrostKnight.Event.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_SetByCaller_AttackType_Light, "FrostKnight.SetByCaller.AttackType.Light");
	UE_DEFINE_GAMEPLAY_TAG(FrostKnight_SetByCaller_AttackType_Heavy, "FrostKnight.SetByCaller.AttackType.Heavy");

	/** Enemy Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee, "Enemy.Ability.Melee");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged, "Enemy.Ability.Ranged");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_UnderAttack, "Enemy.Status.UnderAttack");

	/** Shared tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact,"Shared.Ability.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death,"Shared.Ability.Death");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact,"Shared.Event.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");

	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Dead, "Shared.Status.Dead");
}
