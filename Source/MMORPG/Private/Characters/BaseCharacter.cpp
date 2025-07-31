// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "DebugHelper.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Debug::LOG_W("Position: ({}, {}, {})", 100, 200, 300);
	//Debug::LOG
	//LOG_I("Position: ({}, {}, {})", 100, 200, 300);
	//LOG_W("Position: ({}, {}, {})", 100, 200, 300);
	//LOG_E("Position: ({}, {}, {})", 100, 200, 300);
}


