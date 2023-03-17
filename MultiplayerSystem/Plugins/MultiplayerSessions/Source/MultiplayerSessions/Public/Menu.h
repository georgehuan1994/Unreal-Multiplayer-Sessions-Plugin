// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MultiplayerSessions")
	void MenuSetup(int32 NumOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Lobby")));

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	// Callbacks for the custom delegates on the MultiplayerSessionSubsystem
	UFUNCTION(Category = "MultiplayerSessions")
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION(Category = "MultiplayerSessions")
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION(Category = "MultiplayerSessions")
	void OnStartSession(bool bWasSuccessful);

private:
	UPROPERTY(EditAnywhere, Category = "MultiplayerSessions", META = (BindWidget))
	class UButton* HostButton;
	
	UPROPERTY(EditAnywhere, Category = "MultiplayerSessions", META = (BindWidget))
	UButton* JoinButton;

	UFUNCTION(Category = "MultiplayerSessions")
	void HostButtonClicked();
	
	UFUNCTION(Category = "MultiplayerSessions")
	void JoinButtonClicked();

	void MenuTearDown();

	// Online Session Subsystem
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections{4};
	FString MatchType{TEXT("FreeForAll")};
	FString PathToLobby{TEXT("")};
};
