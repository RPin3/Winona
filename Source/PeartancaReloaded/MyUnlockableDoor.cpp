#include "MyUnlockableDoor.h"
#include "MyPear.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

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
		if (Player && Player->Tags.Contains("HasKey"))
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Puerta abierta"));
			}

			Destroy();
		}
	}
}
