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
class UHeroUIComponent;

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
	UWarriorHeroCombatComponent* WarriorCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UHeroUIComponent* WarriorUIComponent;

public:
	FORCEINLINE UWarriorHeroCombatComponent* GetWarriorCombatComponent() const { return WarriorCombatComponent; }

};
