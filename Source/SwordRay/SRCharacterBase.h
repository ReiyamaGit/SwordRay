// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SRAbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "SRCharacterBase.generated.h"

class USRGameplayAbility;

UCLASS()
class SWORDRAY_API ASRCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()


public :
	UPROPERTY(BlueprintReadWrite, Category = "Abilities")
	USRAbilitySystemComponent* AbilitySystem;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<USRGameplayAbility>> AbilityList;





public:
	// Sets default values for this character's properties
	ASRCharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Implement IAbilitySystemInterface.
	UAbilitySystemComponent* GetAbilitySystemComponent() const
	{
		return AbilitySystem;
	};


	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation = true);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<USRGameplayAbility*>& ActiveAbilities);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
