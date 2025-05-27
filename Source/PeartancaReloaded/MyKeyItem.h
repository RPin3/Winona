#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyKeyItem.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class PEARTANCARELOADED_API AMyKeyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyKeyItem();

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
