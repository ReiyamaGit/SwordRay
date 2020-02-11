// Fill out your copyright notice in the Description page of Project Settings.


#include "SRAbilitySystemComponent.h"
#include "SRCharacterBase.h"
#include "SRGameplayAbility.h"



USRAbilitySystemComponent::USRAbilitySystemComponent() {}

void USRAbilitySystemComponent::GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<USRGameplayAbility*>& ActiveAbilities)
{
	TArray<FGameplayAbilitySpec*> AbilitiesToActivate;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, AbilitiesToActivate, false);

	// Iterate the list of all ability specs
	for (FGameplayAbilitySpec* Spec : AbilitiesToActivate)
	{
		// Iterate all instances on this ability spec
		TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();

		for (UGameplayAbility* ActiveAbility : AbilityInstances)
		{
			ActiveAbilities.Add(Cast<USRGameplayAbility>(ActiveAbility));
		}
	}
}

int32 USRAbilitySystemComponent::GetDefaultAbilityLevel() const
{
	/*ASRCharacterBase* OwningCharacter = Cast<ASRCharacterBase>(OwnerActor);

	if (OwningCharacter)
	{
		return OwningCharacter->GetCharacterLevel();
	}*/
	return 1;
}

USRAbilitySystemComponent* USRAbilitySystemComponent::GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent)
{
	return Cast<USRAbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, LookForComponent));
}

