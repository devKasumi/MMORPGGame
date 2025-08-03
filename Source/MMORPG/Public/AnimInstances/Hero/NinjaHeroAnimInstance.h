// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterAnimInstance.h"
#include "NinjaHeroAnimInstance.generated.h"

class ANinjaHeroCharacter;

/**
 * 
 */
UCLASS()
class MMORPG_API UNinjaHeroAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	ANinjaHeroCharacter* OwningHeroCharacter;
	
};
