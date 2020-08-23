#include "MainPlayerController.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

#include "Beeswax/Actors/FollowCamera.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ACameraActor* MainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		SetViewTarget(MainCamera);
	}
}

void AMainPlayerController::ClientReset_Implementation()
{
	ResetCameraMode();

	bPlayerIsWaiting = (PlayerState == nullptr) || !PlayerState->IsOnlyASpectator();
	ChangeState(NAME_Spectating);
}
