#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDamageObject.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class PEARTANCARELOADED_API AMyDamageObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyDamageObject();

protected:
	virtual void BeginPlay() override;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageAmount = 10.0f;
};
