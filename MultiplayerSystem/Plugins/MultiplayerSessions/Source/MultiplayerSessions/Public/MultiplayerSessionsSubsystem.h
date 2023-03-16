// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Delegates/DelegateCombinations.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "MultiplayerSessionsSubsystem.generated.h"

/** UMenu 回调函数 **/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UMultiplayerSessionsSubsystem();
	
	/** 创建会话 **/
	void CreateSession(int32 NumPublicConnections, FString MatchType);
	
	/** 寻找会话 **/
	void FindSession(int32 MaxSearchResults);

	/** 加入会话 **/
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);

	/** 删除会话 **/
	void DestroySession();

	/** 开始会话 **/
	void StartSession();

	/** 创建会话完成 UMenu 委托 **/
	FMultiplayerOnCreateSessionComplete MultiplayerOnCreateSessionComplete;
	
protected:
	// Online Session Interface 委托回调函数
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);

private:
	// Online Session Interface 指针
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;

	// Online Session Interface 委托
	FOnCreateSessionCompleteDelegate	CreateSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate		FindSessionsCompleteDelegate;
	FOnJoinSessionCompleteDelegate		JoinSessionCompleteDelegate;
	FOnDestroySessionCompleteDelegate	DestroySessionCompleteDelegate;
	FOnStartSessionCompleteDelegate		StartSessionCompleteDelegate;

	FDelegateHandle CreateSessionCompleteDelegateHandle;
	FDelegateHandle FindSessionCompleteDelegateHandle;
	FDelegateHandle JoinSessionCompleteDelegateHandle;
	FDelegateHandle DestroySessionCompleteDelegateHandle;
	FDelegateHandle StartSessionCompleteDelegateHandle;
};
