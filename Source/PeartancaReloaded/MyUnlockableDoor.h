#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyUnlockableDoor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class PEARTANCARELOADED_API AMyUnlockableDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyUnlockableDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
};
