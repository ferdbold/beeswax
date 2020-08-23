#include "Beeswax/Actors/MainPlayerCharacter.h"

#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

#include "Beeswax/Actors/FollowCamera.h"
#include "Beeswax/GameModes/Main/MainPlayerController.h"

void AMainPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AFollowCamera* MainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		MainCamera->AddTarget(this);
	}
}

void AMainPlayerCharacter::Destroyed()
{
	if (AFollowCamera* MainCamera = Cast<AFollowCamera>(UGameplayStatics::GetActorOfClass(this, AFollowCamera::StaticClass())))
	{
		MainCamera->RemoveTarget(this);
	}
}

void AMainPlayerCharacter::OnMoveForward(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMainPlayerCharacter::OnMoveRight(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
