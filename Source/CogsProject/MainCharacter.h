// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "MainCharacter.generated.h"



class UAbilitySystemComponent;
class UCharacterAbility;

UCLASS()
class COGSPROJECT_API AMainCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(BlueprintReadOnly, EditAnywhere);
	UAbilitySystemComponent* AbilityComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere);
	USceneComponent* RotationPoint;

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UCharacterAbility>> StartupAbilities;


	void GiveStartupAbilities();

	void PossessedBy(AController* NewController) override;


private:
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	bool AbilitiesGiven;
};
