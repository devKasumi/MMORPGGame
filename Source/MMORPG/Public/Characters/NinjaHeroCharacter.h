// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "NinjaHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MMORPG_API ANinjaHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ANinjaHeroCharacter();

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
};
