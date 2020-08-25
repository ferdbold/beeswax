#include "MainPlayerController.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

#include "Beeswax/Actors/FollowCamera.h"

AMainPlayerController::AMainPlayerController()
{
	bAutoManageActiveCameraTarget = false;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ACameraActor* MainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		SetViewTarget(MainCamera);
	}
}
