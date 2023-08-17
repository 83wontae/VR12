// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyHUD.h"
#include "Blueprint/UserWidget.h"
#include "LobbyPlayerState.h"

void ALobbyHUD::BeginPlay()
{
	Super::BeginPlay();

	check(HudWidgetClass);

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget->AddToViewport();
}

void ALobbyHUD::BindPlayerState(ALobbyPlayerState* PlayerState)
{
	if (IsValid(PlayerState))
	{
		PlayerState->Fuc_Dele_UpdateUserName.AddDynamic(this, &ALobbyHUD::OnUpdateUserName);
		return;
	}
}

void ALobbyHUD::OnUpdateUserName_Implementation(const FString& userName)
{
}
