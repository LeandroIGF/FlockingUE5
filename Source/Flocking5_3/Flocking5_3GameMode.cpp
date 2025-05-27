// Copyright Epic Games, Inc. All Rights Reserved.

#include "Flocking5_3GameMode.h"
#include "Flocking5_3Character.h"
#include "UObject/ConstructorHelpers.h"

AFlocking5_3GameMode::AFlocking5_3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
