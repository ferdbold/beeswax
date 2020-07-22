// Copyright Epic Games, Inc. All Rights Reserved.

#include "BeeswaxGameMode.h"
#include "BeeswaxCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABeeswaxGameMode::ABeeswaxGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
