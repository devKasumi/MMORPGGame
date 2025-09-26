// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/WeaponBase.h"
#include "Components/BoxComponent.h"
#include "DebugHelper.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	LOG_I("AWeaponBase::AWeaponBase(), {}", "chelsea");
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}


