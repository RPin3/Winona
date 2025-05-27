#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEnemy.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyEnemy();
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> spawnObject;
	UPROPERTY(EditAnywhere)
	float timer;
	UPROPERTY(EditAnywhere)
	float stopTimer;
	
	FTimerHandle timerHandle;
	FTimerHandle stopTimerHandle;
	void ShootBullet();
	void StopShootBullet();
};
