#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayerCharacter.generated.h"

UCLASS(config=Game)
class AMainPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	FORCEINLINE int GetDefaultMaxHealth() const { return DefaultMaxHealth; }

protected:
	void BeginPlay() override;
	void Destroyed() override;

	UFUNCTION(BlueprintCallable, Category="Input")
	void OnMoveForward(float Value);

	UFUNCTION(BlueprintCallable, Category="Input")
	void OnMoveRight(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes", Meta=(ClampMin=0))
	int DefaultMaxHealth{ 0 };
};
