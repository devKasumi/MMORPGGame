// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/HeroInputComponent.h"
#include "HeroGameplayTags.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"

#include "DebugHelper.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	CharacterAbilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(TEXT("CharacterAbilitySystemComponent"));
	CharacterAttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("CharacterAttributeSet"));

}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UHeroInputComponent* HeroInputComponent = CastChecked<UHeroInputComponent>(PlayerComponent);

	HeroInputComponent->BindNativeInputAction(
		InputConfigDataAsset,
		HeroGameplayTags::InputTag_Move,
		ETriggerEvent::Triggered,
		this,
		&ThisClass::Input_Move
	);

	HeroInputComponent->BindNativeInputAction(
		InputConfigDataAsset,
		HeroGameplayTags::InputTag_Look,
		ETriggerEvent::Triggered,
		this,
		&ThisClass::Input_Look
	);
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return GetCharacterAbilitySystemComponent();
}

void ABaseCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABaseCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CharacterAbilitySystemComponent)
	{
		CharacterAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}


