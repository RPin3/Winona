// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MiPlayerController.generated.h"

class UMainHUDWidget;

UCLASS()
class PEARTANCARELOADED_API AMiPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UMainHUDWidget> MainHUDClass;

	UPROPERTY()
	UMainHUDWidget* MainHUD;
	UFUNCTION()
	void ShowNoKeyMessage();
	void HideNoKeyMessage();
	FTimerHandle NoKeyMessageTimerHandle;
	FTimerHandle KeyObtainedMessageTimerHandle;
	void ShowKeyObtainedMessage();
	void HideKeyObtainedMessage();
	UFUNCTION()
	void CreateMainHUD();


};
