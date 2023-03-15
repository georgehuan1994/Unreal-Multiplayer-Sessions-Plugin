// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerSystemGameMode.h"
#include "MultiplayerSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerSystemGameMode::AMultiplayerSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
