#include "MyDamageObject.h"
#include "MyPear.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"

AMyDamageObject::AMyDamageObject()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;
	CollisionBox->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
	CollisionBox->SetGenerateOverlapEvents(true);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AMyDamageObject::BeginPlay()
{
	Super::BeginPlay();
}

void AMyDamageObject::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		AMyPear* Player = Cast<AMyPear>(OtherActor);
		if (Player)
		{
			Player->ReceiveDamage(DamageAmount);
		}
	}
}
