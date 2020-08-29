#include "MainPlayerState.h"

#include "Net/UnrealNetwork.h"

void AMainPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerState, Health);
	DOREPLIFETIME(AMainPlayerState, MaxHealth);
}

void AMainPlayerState::OnHealthChanged_Implementation()
{

}

void AMainPlayerState::OnMaxHealthChanged_Implementation()
{

}
