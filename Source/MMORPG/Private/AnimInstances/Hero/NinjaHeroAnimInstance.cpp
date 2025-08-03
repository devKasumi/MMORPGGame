// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/NinjaHeroAnimInstance.h"
#include "Characters/NinjaHeroCharacter.h"

void UNinjaHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<ANinjaHeroCharacter>(OwningCharacter);
	}
}
