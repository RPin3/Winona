// WinTrigger.cpp

#include "WinTrigger.h"

#include "Blueprint/UserWidget.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

AWinTrigger::AWinTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;
	TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AWinTrigger::OnOverlapBegin);
}

void AWinTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void AWinTrigger::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (VictoryScreenClass && PC && !VictoryScreenInstance)
		{
			VictoryScreenInstance = CreateWidget<UUserWidget>(PC, VictoryScreenClass);
			if (VictoryScreenInstance)
			{
				VictoryScreenInstance->AddToViewport();
				PC->SetInputMode(FInputModeUIOnly());
				PC->bShowMouseCursor = true;
			}
		}
	}
}
