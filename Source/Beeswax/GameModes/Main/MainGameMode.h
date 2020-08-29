#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Beeswax/Actors/MainPlayerCharacter.h"

#include "MainGameMode.generated.h"

UCLASS(minimalapi)
class AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMainGameMode(FObjectInitializer const& ObjectInitializer);

	void PostLogin(APlayerController* NewPlayer) override;
	void Logout(AController* Exiting) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Characters")
	TArray<AMainPlayerCharacter*> AvailableCharacters;
};
