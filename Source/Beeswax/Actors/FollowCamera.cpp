#include "FollowCamera.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

AFollowCamera::AFollowCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	_CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("ZoomBoom"));
	_CameraBoom->SetupAttachment(RootComponent);
	_CameraBoom->TargetArmLength = _ZoomLimits.X;

	GetCameraComponent()->AttachTo(_CameraBoom, USpringArmComponent::SocketName);
}

void AFollowCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdatePosition();
}

void AFollowCamera::UpdatePosition()
{
	const FVector CurrentLocation = GetActorLocation();

	FVector2D ViewportSize;
	GetWorld()->GetGameViewport()->GetViewportSize(ViewportSize);
	
	/** 1. Set camera target on XZ */

	// The middle point of all targets, where the camera needs to focus
	FVector TargetAverage(FVector::ZeroVector);

	// A positive delta means targets are outside of the deadzone and we need to zoom out
	// Negative means we need to zoom in
	float WorstDeltaToDeadzone = -9999999999999999.f;

	for (const auto* Target : _Targets)
	{
		FVector TargetPosition = Target->GetActorLocation();
		TargetPosition.Z += _CameraHeight; // trick camera into targeting actors higher than they actually are to retain pitch

		FVector2D ScreenPosition;
		UGameplayStatics::ProjectWorldToScreen(GetWorld()->GetFirstPlayerController(), TargetPosition, ScreenPosition, false);
		
		// Bring to [0, 1] system
		ScreenPosition.X /= ViewportSize.X; 
		ScreenPosition.Y /= ViewportSize.Y;

		float DeltaToDeadzone = FMath::Abs(ScreenPosition.X) - _Deadzone.X;
		WorstDeltaToDeadzone = FMath::Max(WorstDeltaToDeadzone, DeltaToDeadzone);

		TargetAverage += TargetPosition;
	}
	TargetAverage /= _Targets.Num();
	SetActorLocation(FVector(CurrentLocation.X, TargetAverage.Y, TargetAverage.Z));

	/** 2. Set camera zoom */

	float ZoomAmount = _ZoomSpeed * WorstDeltaToDeadzone;
	_CameraBoom->TargetArmLength = FMath::Clamp(_CameraBoom->TargetArmLength + ZoomAmount, _ZoomLimits.X, _ZoomLimits.Y);
}

void AFollowCamera::AddTarget(AActor* Target)
{
	_Targets.Add(Target);
}

void AFollowCamera::RemoveTarget(AActor* Target)
{
	_Targets.Remove(Target);
}
