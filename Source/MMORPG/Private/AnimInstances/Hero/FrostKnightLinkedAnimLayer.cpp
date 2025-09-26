// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/FrostKnightLinkedAnimLayer.h"
#include "AnimInstances/Hero/FrostKnightHeroAnimInstance.h"

UFrostKnightHeroAnimInstance* UFrostKnightLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UFrostKnightHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}