// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/CharacterAttributeSet.h"
#include "HeroGameplayTags.h"

#include "DebugHelper.h"

struct FCharacterDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FCharacterDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, DefensePower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, DamageTaken, Target, false)
	}
};

static const FCharacterDamageCapture& GetCharacterDamageCapture()
{
	static FCharacterDamageCapture CharacterDamageCapture;
	return CharacterDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	/*Slow way of doing capture*/
	//FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(
	//	UCharacterAttributeSet::StaticClass(),
	//	GET_MEMBER_NAME_CHECKED(UCharacterAttributeSet, AttackPower)
	//);

	//FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefination(
	//	AttackPowerProperty,
	//	EGameplayEffectAttributeCaptureSource::Source,
	//	false
	//);

	//RelevantAttributesToCapture.Add(AttackPowerCaptureDefination);

	RelevantAttributesToCapture.Add(GetCharacterDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetCharacterDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetCharacterDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	//EffectSpec.GetContext().GetSourceObject();
	//EffectSpec.GetContext().GetAbility();
	//EffectSpec.GetContext().GetInstigator();
	//EffectSpec.GetContext().GetEffectCauser();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetCharacterDamageCapture().AttackPowerDef,
		EvaluateParameters,
		SourceAttackPower
	);
	//LOG_I(FColor::MakeRandomColor(), "SourceAttackPower: {}", SourceAttackPower);
	
	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;

	for (const TPair<FGameplayTag, float>& TagMagnitue : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitue.Key.MatchesTagExact(HeroGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitue.Value;
			//LOG_I(FColor::MakeRandomColor(), "BaseDamage: {}", BaseDamage);
		}

		if (TagMagnitue.Key.MatchesTagExact(HeroGameplayTags::Warrior_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitue.Value;
			//LOG_I(FColor::MakeRandomColor(), "UsedLightAttackComboCount: {}", UsedLightAttackComboCount);
		}

		if (TagMagnitue.Key.MatchesTagExact(HeroGameplayTags::Warrior_SetByCaller_AttackType_Heavy))
		{
			//UsedHeavyAttackComboCount = TagMagnitue.Value;
			//LOG_I(FColor::MakeRandomColor(), "UsedHeavyAttackComboCount: {}", UsedHeavyAttackComboCount);
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetCharacterDamageCapture().DefensePowerDef,
		EvaluateParameters,
		TargetDefensePower
	);
	//LOG_I(FColor::MakeRandomColor(), "TargetDefensePower: {}", TargetDefensePower);

	if (UsedLightAttackComboCount != 0)
	{
		const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1) * 0.05 + 1.f;
		BaseDamage *= DamageIncreasePercentLight;
		//LOG_I(FColor::MakeRandomColor(), "ScaledBaseDamageLight: {}", BaseDamage);
	}

	if (UsedHeavyAttackComboCount != 0)
	{
		const float DamageIncreasePercentHeavy = UsedHeavyAttackComboCount * 0.15f + 1.f;
		BaseDamage *= DamageIncreasePercentHeavy;
		//LOG_I(FColor::MakeRandomColor(), "ScaledBaseDamageHeavy: {}", BaseDamage);
	}

	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	//LOG_I(FColor::MakeRandomColor(), "FinalDamageDone: {}", FinalDamageDone);

	if (FinalDamageDone > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetCharacterDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamageDone
			)
		);
	}
}
