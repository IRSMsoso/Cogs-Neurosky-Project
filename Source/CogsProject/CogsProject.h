// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
	// 0 None
	None			UMETA(DisplayName = "None"),
	// 1 LMB
	Shoot			UMETA(DisplayName = "Shoot"),
	// 2 RMB
	Aim				UMETA(DisplayName = "Aim"),
};