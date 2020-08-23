#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "FollowCamera.generated.h"

UCLASS()
class BEESWAX_API AFollowCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:
	void Tick(float DeltaSeconds) override;

	void AddTarget(AActor* Target);
	void RemoveTarget(AActor* Target);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Targeting")
	TArray<AActor*> Targets;

private:
	void UpdatePosition();
};
