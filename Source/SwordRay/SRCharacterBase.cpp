// Fill out your copyright notice in the Description page of Project Settings.


#include "SRCharacterBase.h"
#include "SRGameplayAbility.h"


// Sets default values
ASRCharacterBase::ASRCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystem = CreateDefaultSubobject<USRAbilitySystemComponent>("Ability Sysytem Component");

}

// Called when the game starts or when spawned
void ASRCharacterBase::BeginPlay()
{
	Super::BeginPlay();


	for (TSubclassOf<USRGameplayAbility>& StartupAbility : AbilityList)
	{
		AbilitySystem->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, INDEX_NONE, this));
	}

	
	
}

// Called every frame
void ASRCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASRCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



bool ASRCharacterBase::ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation)
{
	if (AbilitySystem)
	{
		return AbilitySystem->TryActivateAbilitiesByTag(AbilityTags, bAllowRemoteActivation);
	}

	return false;
}

void ASRCharacterBase::GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<USRGameplayAbility*>& ActiveAbilities)
{
	if (AbilitySystem)
	{
		AbilitySystem->GetActiveAbilitiesWithTags(AbilityTags, ActiveAbilities);
	}
}