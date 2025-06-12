// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUDWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UMainHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainHUDWidget::UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo)
{
	if (AmmoText)
	{
		AmmoText->SetText(FText::FromString(FString::Printf(TEXT("Ammo: %d / %d"), CurrentAmmo, MaxAmmo)));
	}
}

void UMainHUDWidget::UpdateHealth(float HealthPercent)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(HealthPercent);
	}
}

void UMainHUDWidget::ShowNoKeyMessage()
{
	if (NoKeyMessageText)
	{
		NoKeyMessageText->SetVisibility(ESlateVisibility::Visible);
	}
}

void UMainHUDWidget::HideNoKeyMessage()
{
	if (NoKeyMessageText)
	{
		NoKeyMessageText->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UMainHUDWidget::ShowKeyObtainedMessage()
{
	if (KeysText)
	{
		KeysText->SetVisibility(ESlateVisibility::Visible);
	}
}


void UMainHUDWidget::HideKeyObtainedMessage()
{
	if (KeysText)
	{
		KeysText->SetVisibility(ESlateVisibility::Hidden);
	}
}
