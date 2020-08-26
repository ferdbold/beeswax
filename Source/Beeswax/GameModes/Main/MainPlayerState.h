#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MainPlayerState.generated.h"

UCLASS()
class BEESWAX_API AMainPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AMainPlayerState();
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE int GetHealth() const { return _Health; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE int GetMaxHealth() const { return _MaxHealth; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", ReplicatedUsing=OnHealthChanged, Meta=(ClampMin=0))
	int _Health{ 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", ReplicatedUsing=OnMaxHealthChanged, Meta=(ClampMin=0))
	int _MaxHealth{ 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", Meta=(ClampMin=0))
	int _DefaultMaxHealth{ 0 };

	UFUNCTION(BlueprintNativeEvent)
	void OnHealthChanged();

	UFUNCTION(BlueprintNativeEvent)
	void OnMaxHealthChanged();
};
