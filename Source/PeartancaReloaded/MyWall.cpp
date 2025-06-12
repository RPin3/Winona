// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWall.h"

#include "MyBullet.h"
#include "MyPear.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyWall::AMyWall()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->SetCollisionObjectType(ECC_Pawn);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionBox->SetGenerateOverlapEvents(true);

	CollisionBox ->OnComponentBeginOverlap.AddDynamic(this, &AMyWall::OnOverlapBegin);

}

void AMyWall::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
	
		AMyBullet* bullet = Cast<AMyBullet>(OtherActor);
		if (bullet)
		{
			AMyWall::Health -= bullet->Damage;
			if (Health <= 0)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Mori");
				Destroy();
			}
		}

	}
}

// Called when the game starts or when spawned
void AMyWall::BeginPlay()
{
	Super::BeginPlay();
	
}

