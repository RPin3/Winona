#include "MyUnlockableDoor.h"

#include "MainHUDWidget.h"
#include "MiPlayerController.h"
#include "MyPear.h"
#include "PeartancaHUD.h"
#include "WallActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/HUD.h"
#include "Kismet/GameplayStatics.h"

AMyUnlockableDoor::AMyUnlockableDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;
	CollisionBox->SetBoxExtent(FVector(64.f, 32.f, 128.f)); // Puerta alta
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
	CollisionBox->SetGenerateOverlapEvents(true);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AMyUnlockableDoor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyUnlockableDoor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		AMyPear* Player = Cast<AMyPear>(OtherActor);
		if (Player)
		{
			APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			if (PC)
			{
				AMiPlayerController* MyPC = Cast<AMiPlayerController>(PC);
				if (MyPC && Player->KeyCount <= 0)
				{
					MyPC->ShowNoKeyMessage();
				}
			}

			if (Player->KeyCount > 0)
			{
				Player->KeyCount--;
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("Puerta desbloqueada"));
				}
				Destroy();
			}
		}
	}
}
