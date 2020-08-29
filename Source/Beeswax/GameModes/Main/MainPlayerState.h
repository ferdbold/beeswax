#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MainPlayerState.generated.h"

UCLASS()
class BEESWAX_API AMainPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE int GetHealth() const { return Health; }
	FORCEINLINE void SetHealth(int value) { Health = value; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE int GetMaxHealth() const { return MaxHealth; }
	FORCEINLINE void SetMaxHealth(int value) { MaxHealth = value; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", ReplicatedUsing=OnHealthChanged, Meta=(ClampMin=0))
	int Health{ 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", ReplicatedUsing=OnMaxHealthChanged, Meta=(ClampMin=0))
	int MaxHealth{ 0 };

	UFUNCTION(BlueprintNativeEvent)
	void OnHealthChanged();

	UFUNCTION(BlueprintNativeEvent)
	void OnMaxHealthChanged();
};
