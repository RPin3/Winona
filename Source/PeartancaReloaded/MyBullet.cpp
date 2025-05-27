#include "MyBullet.h"

AMyBullet::AMyBullet()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMyBullet::BeginPlay()
{
	Super::BeginPlay();

	// Se destruye automáticamente después de 3 segundos
	SetLifeSpan(3.0f);
}

void AMyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(VelocityX, VelocityY, VelocityZ));
}

void AMyBullet::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other && Other != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow,
				TEXT("Golpeó a: ") + Other->GetName());
		}

		Destroy();
	}
}
