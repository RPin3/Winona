// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUDWidget.h"
#include "PeartancaHUD.generated.h"

UCLASS()
class PEARTANCARELOADED_API APeartancaHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="HUD")
	TSubclassOf<UMainHUDWidget> MainHUDWidgetClass;

	UPROPERTY()
	UMainHUDWidget* MainHUDWidget;

	void ShowNoKeyMessage();
};
