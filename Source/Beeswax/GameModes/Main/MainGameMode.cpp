#include "Beeswax/GameModes/Main/MainGameMode.h"

#include "Beeswax/GameModes/Main/MainGameState.h"
#include "Beeswax/GameModes/Main/MainPlayerController.h"
#include "Beeswax/GameModes/Main/MainPlayerState.h"

AMainGameMode::AMainGameMode(const FObjectInitializer& ObjectInitializer)
{
	GameStateClass = AMainGameState::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
	PlayerStateClass = AMainPlayerState::StaticClass();
}
