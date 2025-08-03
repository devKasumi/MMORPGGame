// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterAnimInstance.h"
#include "ArcherHeroAnimInstance.generated.h"

class AArcherHeroCharacter;

/**
 * 
 */
UCLASS()
class MMORPG_API UArcherHeroAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AArcherHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime;
	
};
