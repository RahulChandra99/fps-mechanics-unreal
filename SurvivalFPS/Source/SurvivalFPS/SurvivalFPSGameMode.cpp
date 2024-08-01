// Copyright Epic Games, Inc. All Rights Reserved.

#include "SurvivalFPSGameMode.h"
#include "SurvivalFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASurvivalFPSGameMode::ASurvivalFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
