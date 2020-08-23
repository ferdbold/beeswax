#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayerCharacter.generated.h"

class AFollowCamera;

UCLASS(config=Game)
class AMainPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Input")
	void OnMoveForward(float Value);

	UFUNCTION(BlueprintCallable, Category="Input")
	void OnMoveRight(float Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	AFollowCamera* MainCamera;
};
