#include "Beeswax/Actors/MainPlayerCharacter.h"

#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

#include "Beeswax/Actors/FollowCamera.h"
#include "Beeswax/GameModes/Main/MainPlayerController.h"

void AMainPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AFollowCamera* mainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		mainCamera->AddTarget(this);
	}
}

void AMainPlayerCharacter::Destroyed()
{
	Super::Destroyed();

	if (AFollowCamera* mainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		mainCamera->RemoveTarget(this);
	}
}

void AMainPlayerCharacter::OnMoveForward(float value)
{
	if (Controller && (value != 0.0f))
	{
		// find out which way is forward
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator yawRotation(0, rotation.Yaw, 0);

		// get forward vector
		const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, value);
	}
}

void AMainPlayerCharacter::OnMoveRight(float value)
{
	if (Controller && (value != 0.0f))
	{
		// find out which way is right
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator yawRotation(0, rotation.Yaw, 0);
	
		// get right vector 
		const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(direction, value);
	}
}
