// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CharacterFunctionLibrary.generated.h"

class UCharacterAbilitySystemComponent;

UENUM()
enum class ECharacterConfirmType : uint8
{
	Yes,
	No
};

/**
 * 
 */
UCLASS()
class MMORPG_API UCharacterFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UCharacterAbilitySystemComponent* NativeGetCharacterASCFromActor(AActor* InActor);
	
	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Character|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ECharacterConfirmType& OutConfirmType);
};
