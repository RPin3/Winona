// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenuWidget.h"

#include "MiPlayerController.h"
#include "MainHUDWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UStartMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UStartMenuWidget::OnStartButtonClicked);
	}

	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UStartMenuWidget::OnExitButtonClicked);
	}
}
void UStartMenuWidget::OnStartButtonClicked()
{
	RemoveFromParent();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		PC->SetInputMode(FInputModeGameOnly());
		PC->bShowMouseCursor = false;

		AMiPlayerController* MyPC = Cast<AMiPlayerController>(PC);
		if (MyPC)
		{
			MyPC->CreateMainHUD();
		}
	}
}


void UStartMenuWidget::OnExitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}
