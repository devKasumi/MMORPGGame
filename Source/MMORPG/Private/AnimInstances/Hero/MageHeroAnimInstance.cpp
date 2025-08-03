// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/MageHeroAnimInstance.h"
#include "Characters/MageHeroCharacter.h"

void UMageHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AMageHeroCharacter>(OwningCharacter);
	}
}

void UMageHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
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
