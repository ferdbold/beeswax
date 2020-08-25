#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "FollowCamera.generated.h"

UCLASS()
class BEESWAX_API AFollowCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:
	AFollowCamera();

	void Tick(float DeltaSeconds) override;

	void AddTarget(AActor* Target);
	void RemoveTarget(AActor* Target);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* _CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Targeting")
	TArray<AActor*> _Targets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targeting")
	FVector2D _CameraOffset { -800.f, 450.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zoom")
	FVector2D _Deadzone { 0.8, 0.8 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zoom")
	FVector2D _ZoomLimits { 0.f, 1500.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Zoom")
	float _ZoomSpeed { 200.f };

private:
	void UpdatePosition();
};
