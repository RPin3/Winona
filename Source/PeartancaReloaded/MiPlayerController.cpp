// Fill out your copyright notice in the Description page of Project Settings.


#include "MiPlayerController.h"
#include "MainHUDWidget.h"

void AMiPlayerController::BeginPlay()
{
	Super::BeginPlay();


}

void AMiPlayerController::ShowNoKeyMessage()
{
	if (MainHUD)
	{
		MainHUD->ShowNoKeyMessage();

		// Cancelar cualquier timer previo
		GetWorld()->GetTimerManager().ClearTimer(NoKeyMessageTimerHandle);

		// Setear timer para ocultarlo en 2 segundos
		GetWorld()->GetTimerManager().SetTimer(
			NoKeyMessageTimerHandle,
			this,
			&AMiPlayerController::HideNoKeyMessage,
			2.0f,
			false
		);
	}
}

void AMiPlayerController::HideNoKeyMessage()
{
	if (MainHUD)
	{
		MainHUD->HideNoKeyMessage();
	}
}

void AMiPlayerController::ShowKeyObtainedMessage()
{
	if (MainHUD)
	{
		MainHUD->ShowKeyObtainedMessage();
		GetWorld()->GetTimerManager().ClearTimer(KeyObtainedMessageTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(
			KeyObtainedMessageTimerHandle,
			this,
			&AMiPlayerController::HideKeyObtainedMessage,
			2.0f,
			false
		);
	}
}

void AMiPlayerController::HideKeyObtainedMessage()
{
	if (MainHUD)
	{
		MainHUD->HideKeyObtainedMessage();
	}
}
void AMiPlayerController::CreateMainHUD()
{
	if (MainHUDClass && !MainHUD)
	{
		MainHUD = CreateWidget<UMainHUDWidget>(this, MainHUDClass);
		if (MainHUD)
		{
			MainHUD->AddToViewport();
		}
	}
}
