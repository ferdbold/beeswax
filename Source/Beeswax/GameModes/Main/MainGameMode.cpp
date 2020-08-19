#include "Beeswax/GameModes/Main/MainGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "Beeswax/Actors/MainPlayerCharacter.h"

AMainGameMode::AMainGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
