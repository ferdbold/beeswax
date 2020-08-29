#include "Beeswax/GameModes/Main/MainGameMode.h"

#include "Kismet/GameplayStatics.h"

#include "Beeswax/GameModes/Main/MainGameState.h"
#include "Beeswax/GameModes/Main/MainPlayerController.h"
#include "Beeswax/GameModes/Main/MainPlayerState.h"

AMainGameMode::AMainGameMode(FObjectInitializer const& ObjectInitializer)
{
	GameStateClass = AMainGameState::StaticClass();
	PlayerControllerClass = AMainPlayerController::StaticClass();
	PlayerStateClass = AMainPlayerState::StaticClass();

	bStartPlayersAsSpectators = true;

	// Fetch all available characters
	TArray<AActor*> characters;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AMainPlayerCharacter::StaticClass(), FName("PlayerCharacter"), characters);
	for (auto* character : characters)
	{
		AvailableCharacters.Add(Cast<AMainPlayerCharacter>(character));
	}
}

void AMainGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (AvailableCharacters.Num() == 0)
	{
		ensureMsgf(false, TEXT("No more characters available, aborting"));
		return;
	}

	// Allocate a character to this player from the pool
	NewPlayer->Possess(AvailableCharacters[0]);
	AvailableCharacters.RemoveAt(0);
}

void AMainGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	// Add the character back to the available pool
	if (AMainPlayerCharacter* character = Cast<AMainPlayerCharacter>(Exiting->GetPawn()))
	{
		AvailableCharacters.Add(character);
		Exiting->UnPossess();
	}
}
