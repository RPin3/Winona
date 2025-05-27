#include "MyEnemy.h"

AMyEnemy::AMyEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timerHandle, this, &AMyEnemy::ShootBullet, timer, true);
	GetWorldTimerManager().SetTimer(stopTimerHandle, this, &AMyEnemy::StopShootBullet, stopTimer);

}
void AMyEnemy::ShootBullet()
{
	if (spawnObject)
	{
		FVector spawnLocation = GetActorLocation();
		FRotator spawnRotation = GetActorRotation();

		GetWorld()->SpawnActor<AActor>(spawnObject, spawnLocation, spawnRotation);
	}
}

void AMyEnemy::StopShootBullet()
{
	GetWorldTimerManager().ClearTimer(timerHandle);
}



