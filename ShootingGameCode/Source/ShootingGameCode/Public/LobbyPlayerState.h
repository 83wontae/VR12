// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LobbyPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_UpdateUserName_OneParam, const FString&, UserName);

/**
 * 
 */
UCLASS()
class SHOOTINGGAMECODE_API ALobbyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ALobbyPlayerState();

public:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnRep_UserName();

	void UpdateBind();

	void SetUserName(const FString& name);

public:
	UPROPERTY(ReplicatedUsing = OnRep_UserName)
	FString UserName;

	FDele_UpdateUserName_OneParam Fuc_Dele_UpdateUserName;

	FTimerHandle th_UpdateBind;
};
