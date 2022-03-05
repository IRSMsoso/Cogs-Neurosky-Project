// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "CharacterAbility.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	AbilityComponent = CreateDefaultSubobject<UAbilitySystemComponent>("Ability Component");

	RotationPoint = CreateDefaultSubobject<USceneComponent>("Rotation Point");


	RotationPoint->SetupAttachment(GetCapsuleComponent());
	GetMesh()->SetupAttachment(RotationPoint);

	AbilityComponent->SetIsReplicated(true);
	AbilityComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

}

void AMainCharacter::GiveStartupAbilities()
{

	if (AbilitiesGiven || !IsValid(AbilityComponent) || GetLocalRole() != ROLE_Authority)
		return;


	for (TSubclassOf<UCharacterAbility>& StartupAbility : StartupAbilities) {

		AbilityComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID), this));

	}

	AbilitiesGiven = true;
}

void AMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilityComponent) {
		AbilityComponent->InitAbilityActorInfo(this, this);
	}

	GiveStartupAbilities();

}


void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	AbilityComponent->BindAbilityActivationToInputComponent(PlayerInputComponent,
		FGameplayAbilityInputBinds(
			FString("ConfirmTarget"),
			FString("CancelTarget"),
			"EAbilityInputID",
			static_cast<int32>(EAbilityInputID::Confirm),
			static_cast<int32>(EAbilityInputID::Cancel)
		)
	);
}

UAbilitySystemComponent* AMainCharacter::GetAbilitySystemComponent() const
{
	return AbilityComponent;
}

