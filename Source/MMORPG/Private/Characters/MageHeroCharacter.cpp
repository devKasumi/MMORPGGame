// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MageHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"

#include "DebugHelper.h"

AMageHeroCharacter::AMageHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 200.f;
	SpringArm->SocketOffset = FVector(0.f, 55.f, 65.f);
	SpringArm->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void AMageHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CharacterAbilitySystemComponent && CharacterAttributeSet)
	{
		const FString ASCText = FString::Printf(TEXT("Owner Actor: %s, AvatarActor: %s"),
			*CharacterAbilitySystemComponent->GetOwnerActor()->GetActorLabel(),
			*CharacterAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
		LOG_I("Ability system component valid. {}", Debug::ConvertToStdString(*ASCText));
		LOG_I("AttributeSet valid. {}", Debug::ConvertToStdString(*ASCText));
	}
}
