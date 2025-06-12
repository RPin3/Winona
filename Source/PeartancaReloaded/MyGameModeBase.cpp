#include "MyGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (StartMenuWidgetClass)
	{
		StartMenuWidget = CreateWidget<UUserWidget>(GetWorld(), StartMenuWidgetClass);
		if (StartMenuWidget)
		{
			StartMenuWidget->AddToViewport();

			// Bloquea input de juego y habilita solo UI
			APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			if (PC)
			{
				PC->SetInputMode(FInputModeUIOnly());
				PC->bShowMouseCursor = true;
			}
		}
	}
}
