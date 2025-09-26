// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterAnimInstance.h"
#include "FrostKnightHeroAnimInstance.generated.h"

class AFrostKnightHeroCharacter;

/**
 * 
 */
UCLASS()
class MMORPG_API UFrostKnightHeroAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AFrostKnightHeroCharacter* OwningHeroCharacter;
	
};
