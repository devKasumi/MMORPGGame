// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/ArcherHeroAnimInstance.h"
#include "Characters/ArcherHeroCharacter.h"

void UArcherHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AArcherHeroCharacter>(OwningCharacter);
	}
}

void UArcherHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
