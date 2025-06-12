// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUDWidget.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class PEARTANCARELOADED_API UMainHUDWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	virtual void NativeOnInitialized() override;

	void UpdateAmmo(int32 CurrentAmmo, int32 MaxAmmo);
	void UpdateHealth(float HealthPercent);
	void ShowNoKeyMessage();
	void HideNoKeyMessage();

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* KeysText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* NoKeyMessageText;

	UFUNCTION(BlueprintCallable)
	void ShowKeyObtainedMessage();

	UFUNCTION(BlueprintCallable)
	void HideKeyObtainedMessage();
	

	
};
