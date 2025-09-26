// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "CharacterTypes/CharacterStructTypes.h"
#include "DataAsset_FrostKnightStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class MMORPG_API UDataAsset_FrostKnightStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FFrostKnightHeroAbilitySet> FrostKnightHeroStartUpAbilitySets;

};
