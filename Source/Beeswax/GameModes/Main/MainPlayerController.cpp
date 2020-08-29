#include "MainPlayerController.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

#include "Beeswax/Actors/FollowCamera.h"
#include "Beeswax/Actors/MainPlayerCharacter.h"
#include "Beeswax/GameModes/Main/MainPlayerState.h"

AMainPlayerController::AMainPlayerController()
{
	bAutoManageActiveCameraTarget = false;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Set view target to main camera
	if (ACameraActor* mainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		SetViewTarget(mainCamera);
	}

	// Assign default health to state
	AMainPlayerState* playerState = GetPlayerState<AMainPlayerState>();
	AMainPlayerCharacter const* character = Cast<AMainPlayerCharacter>(GetPawn());
	if (playerState && character)
	{
		int const defaultHealth = character->GetDefaultMaxHealth();
		playerState->SetMaxHealth(defaultHealth);
		playerState->SetHealth(defaultHealth);
	}
}
