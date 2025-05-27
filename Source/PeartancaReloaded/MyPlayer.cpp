#include "MyPlayer.h"

#include "MyBullet.h"
#include "Components/BoxComponent.h"

AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->SetCollisionObjectType(ECC_Pawn);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionBox->SetGenerateOverlapEvents(true);

	CollisionBox ->OnComponentBeginOverlap.AddDynamic(this, &AMyPlayer::OnOverlapBegin);
}


void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(10, 0, 0));
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Choque contra algo");
		}
		AMyBullet* bullet = Cast<AMyBullet>(OtherActor);
		AMyPlayer::Health -= bullet->Damage;
		if (Health <= 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Mori");
		}
	}
}
