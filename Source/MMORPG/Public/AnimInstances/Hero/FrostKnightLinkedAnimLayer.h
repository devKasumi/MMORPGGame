// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BaseAnimInstance.h"
#include "FrostKnightLinkedAnimLayer.generated.h"

class UFrostKnightHeroAnimInstance;

/**
 * 
 */
UCLASS()
class MMORPG_API UFrostKnightLinkedAnimLayer : public UBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (NotBlueprintThreadSafe))
	UFrostKnightHeroAnimInstance* GetHeroAnimInstance() const;
	
};
