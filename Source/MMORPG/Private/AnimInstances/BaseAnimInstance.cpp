// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/BaseAnimInstance.h"
#include "CharacterFunctionLibrary.h"

bool UBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
    if (APawn* OwningPawn = TryGetPawnOwner())
    {
		return UCharacterFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
    }

	return false;
}
