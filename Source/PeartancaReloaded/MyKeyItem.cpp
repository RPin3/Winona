#include "MyKeyItem.h"
#include "MyPear.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

AMyKeyItem::AMyKeyItem()
{
	PrimaryActorTick.bCanEverTick = false;

	// Crear collider como root
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
	CollisionBox->SetGenerateOverlapEvents(true);

	// Crear mesh como hijo del collider
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // No interferir con el collider principal
}

void AMyKeyItem::BeginPlay()
{
	Super::BeginPlay();
}

void AMyKeyItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		AMyPear* Player = Cast<AMyPear>(OtherActor);
		if (Player && !Player->Tags.Contains("HasKey"))
		{
			Player->Tags.Add("HasKey");

			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Llave obtenida"));
			}

			Destroy();
		}
	}
}

