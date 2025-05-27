#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBullet.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyBullet();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VelocityX = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VelocityY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float VelocityZ;
	UPROPERTY(EditAnywhere)
	float Damage;

protected:
	virtual void BeginPlay() override;

	// Llamado al chocar con otro objeto
	virtual void NotifyHit(
		class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit
	) override;
};
