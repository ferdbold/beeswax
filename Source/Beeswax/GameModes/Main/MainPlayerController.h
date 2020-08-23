#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

UCLASS()
class BEESWAX_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// obfuscate PlayerController to prevent resetting viewtarget
	void ClientReset_Implementation(); 

protected:
	void BeginPlay() override;
};
