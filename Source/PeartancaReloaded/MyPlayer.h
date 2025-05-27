#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlayer.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyPlayer : public AActor
{
	GENERATED_BODY()

public:

	AMyPlayer();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) //ver pero no usar
	float number;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) //ver y usar
	FColor color;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Health;
	protected:
	virtual void BeginPlay() override;
};