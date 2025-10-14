// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UDataAsset_InputConfig;
struct FInputActionValue;
class UWarriorHeroCombatComponent;

/**
 * 
 */
UCLASS()
class MMORPG_API AWarriorHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerComponent) override;
	AWarriorHeroCharacter();

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UWarriorHeroCombatComponent* WarriorCombatComponent;

public:
	FORCEINLINE UWarriorHeroCombatComponent* GetWarriorCombatComponent() const { return WarriorCombatComponent; }

};
