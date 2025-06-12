// Fill out your copyright notice in the Description page of Project Settings.

#include "PeartancaHUD.h"
#include "Blueprint/UserWidget.h"

void APeartancaHUD::BeginPlay()
{
	Super::BeginPlay();
	if (MainHUDWidgetClass)
	{
		MainHUDWidget = CreateWidget<UMainHUDWidget>(GetWorld(), MainHUDWidgetClass);
		if (MainHUDWidget)
		{
			MainHUDWidget->AddToViewport();
		}
	}
}

void APeartancaHUD::ShowNoKeyMessage()
{
	if (MainHUDWidget)
	{
		MainHUDWidget->ShowNoKeyMessage();
	}
}
