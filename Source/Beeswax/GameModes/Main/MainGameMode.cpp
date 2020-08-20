#include "Beeswax/GameModes/Main/MainGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "Beeswax/Actors/MainPlayerCharacter.h"
#include "Beeswax/GameModes/Main/MainGameState.h"
#include "Beeswax/GameModes/Main/MainPlayerController.h"
#include "Beeswax/GameModes/Main/MainPlayerState.h"

AMainGameMode::AMainGameMode(const FObjectInitializer& ObjectInitializer)
{
	GameStateClass = AMainGameState::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
	PlayerStateClass = AMainPlayerState::StaticClass();

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
