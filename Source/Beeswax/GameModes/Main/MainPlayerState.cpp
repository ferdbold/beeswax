#include "MainPlayerState.h"

#include "Net/UnrealNetwork.h"

AMainPlayerState::AMainPlayerState()
{
	_Health = _MaxHealth = _DefaultMaxHealth;
}

void AMainPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerState, _Health);
	DOREPLIFETIME(AMainPlayerState, _MaxHealth);
}

void AMainPlayerState::OnHealthChanged_Implementation()
{

}

void AMainPlayerState::OnMaxHealthChanged_Implementation()
{

}
