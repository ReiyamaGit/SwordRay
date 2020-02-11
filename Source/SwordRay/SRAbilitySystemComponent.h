// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SRAbilitySystemComponent.generated.h"

class USRGameplayAbility;

/**
 * 
 */
UCLASS()
class SWORDRAY_API USRAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	USRAbilitySystemComponent();


	/** Returns a list of currently active ability instances that match the tags */
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<USRGameplayAbility*>& ActiveAbilities);

	/** Returns the default level used for ability activations, derived from the character */
	int32 GetDefaultAbilityLevel() const;

	/** Version of function in AbilitySystemGlobals that returns correct type */
	static USRAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);

};
