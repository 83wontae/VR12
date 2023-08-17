// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "LobbyPlayerState.h"
#include "ShootingGameInstance.h"

ALobbyPlayerController::ALobbyPlayerController()
{
}

void ALobbyPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("(Server)OnPossess"));
	ResClientPossess();
}

void ALobbyPlayerController::ResClientPossess_Implementation()
{
	UShootingGameInstance* GameInst = Cast<UShootingGameInstance>(GetGameInstance());
	if (GameInst == nullptr)
		return;

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("(Client)ResClientPossess PlayerName=%s"), *GameInst->GetPlayerName()));

	ReqReName(GameInst->GetPlayerName());
}

void ALobbyPlayerController::ReqReName_Implementation(const FString& NewName)
{
	ALobbyPlayerState* ps = Cast<ALobbyPlayerState>(PlayerState);
	if (ps == nullptr)
		return;

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("(Server)ReqReName NewName=%s"), *NewName));

	ps->SetUserName(NewName);
}
