// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "LobbyHUD.h"

ALobbyPlayerState::ALobbyPlayerState()
{
	UserName = "UserName";
}

void ALobbyPlayerState::BeginPlay()
{
	UpdateBind();
}

void ALobbyPlayerState::OnRep_UserName()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("OnRep_PlayerName=%s"), *UserName));

	if (Fuc_Dele_UpdateUserName.IsBound())
		Fuc_Dele_UpdateUserName.Broadcast(UserName);
}

void ALobbyPlayerState::UpdateBind()
{
	APlayerController* player0 = GetWorld()->GetFirstPlayerController();
	if (player0)
	{
		ALobbyHUD* pHud = Cast<ALobbyHUD>(player0->GetHUD());
		if (pHud)
		{
			pHud->BindPlayerState(this);
			return;
		}
	}

	FTimerManager& timerMgr = GetWorldTimerManager();
	timerMgr.SetTimer(th_UpdateBind, this, &ALobbyPlayerState::UpdateBind, 0.1f, false);
}

void ALobbyPlayerState::SetUserName(const FString& name)
{
	UserName = name;

	OnRep_UserName();
}

void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerState, UserName);
}