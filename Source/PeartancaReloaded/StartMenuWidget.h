// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartMenuWidget.generated.h"

class UButton;
UCLASS()
class PEARTANCARELOADED_API UStartMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

public:
	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton;

	UFUNCTION()
	void OnStartButtonClicked();

	UFUNCTION()
	void OnExitButtonClicked();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	TSubclassOf<class UMainHUDWidget> MainHUDWidgetClass;

	UPROPERTY()
	UMainHUDWidget* MainHUDWidget;

};
