// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SRGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class SWORDRAY_API USRGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()



public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbility")
	class UAnimMontage* MontagoToPlay;
	
};
