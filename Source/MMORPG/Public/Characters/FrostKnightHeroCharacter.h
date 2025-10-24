// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "FrostKnightHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;
class UFrostKnightHeroCombatComponent;
class UPoseableMeshComponent;
class UHeroUIComponent;

/**
 * 
 */
UCLASS()
class MMORPG_API AFrostKnightHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AFrostKnightHeroCharacter();

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface

	//~ Begin IPawnUIInterface Interface.
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	virtual UHeroUIComponent* GetHeroUIComponent() const override;
	//~ End IPawnUIInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UFrostKnightHeroCombatComponent* FrostKnightCombatComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UHeroUIComponent* FrostKnightUIComponent;

public:
	FORCEINLINE UFrostKnightHeroCombatComponent* GetFrostKnightCombatComponent() const { return FrostKnightCombatComponent; }
	
};
