// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "HeroController.generated.h"

/**
 * 
 */
UCLASS()
class MMORPG_API AHeroController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	AHeroController();

	//~ Begin IGenericTeamAgentInterface Interface.
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End IGenericTeamAgentInterface Interface

private:
	FGenericTeamId HeroTeamId;
	
};
