// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/CharacterAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CharacterFunctionLibrary.h"
#include "HeroGameplayTags.h"
#include "Interfaces/PawnUIInterface.h"
#include "Components/UI/PawnUIComponent.h"
#include "Components/UI/HeroUIComponent.h"

#include "DebugHelper.h"

UCharacterAttributeSet::UCharacterAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}
	//IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(Data.Target.GetAvatarActor());
	//UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s did not implement IPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	UPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();

	checkf(PawnUIComponent, TEXT("Couldn't extract a PawnUIComponent from %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
	}
	
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());
		SetCurrentRage(NewCurrentRage);
		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage() / GetMaxRage());
		}
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();
		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		//LOG_I(FColor::MakeRandomColor(), "Old Health: {}, Damage Done: {}, NewCurrentHealth: {}", OldHealth, DamageDone, NewCurrentHealth);

		//Notify the UI
		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());

		if (GetCurrentHealth() == 0.f)
		{
			UCharacterFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), HeroGameplayTags::Shared_Status_Dead);
		}
	}
}
