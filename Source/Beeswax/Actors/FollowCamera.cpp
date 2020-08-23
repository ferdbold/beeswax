#include "FollowCamera.h"

void AFollowCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdatePosition();
}

void AFollowCamera::UpdatePosition()
{
	FVector Average(FVector::ZeroVector);
	for (const auto* Target : Targets)
	{
		Average += Target->GetActorLocation();
	}
	Average /= Targets.Num();

	const FVector CurrentLocation = GetActorLocation();
	SetActorLocation(FVector(CurrentLocation.X, Average.Y, CurrentLocation.Z));
}

void AFollowCamera::AddTarget(AActor* Target)
{
	Targets.Add(Target);
}

void AFollowCamera::RemoveTarget(AActor* Target)
{
	Targets.Remove(Target);
}
