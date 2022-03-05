// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CogsProject.h"
#include "CharacterAbility.generated.h"

/**
 * 
 */
UCLASS()
class COGSPROJECT_API UCharacterAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Input")
	EAbilityInputID AbilityInputID;


	
};
