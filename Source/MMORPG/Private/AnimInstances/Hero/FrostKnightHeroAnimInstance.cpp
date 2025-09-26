// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/FrostKnightHeroAnimInstance.h"
#include "Characters/FrostKnightHeroCharacter.h"

void UFrostKnightHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AFrostKnightHeroCharacter>(OwningCharacter);
	}
}

void UFrostKnightHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
