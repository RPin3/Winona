// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpawnerActor.h"

AMySpawnerActor::AMySpawnerActor()
{
}

void AMySpawnerActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle1, this, &AMySpawnerActor::SpawnObjeto1, 0.1f, false);
	GetWorldTimerManager().SetTimer(TimerHandle2, this, &AMySpawnerActor::SpawnObjeto2, TiempoEntreSpawns, false);
	GetWorldTimerManager().SetTimer(TimerHandle3, this, &AMySpawnerActor::SpawnObjeto3, TiempoEntreSpawns * 2, false);
	GetWorldTimerManager().SetTimer(TimerHandleDestruir, this, &AMySpawnerActor::Autodestruir, TiempoEntreSpawns * 3, false);
}

void AMySpawnerActor::SpawnObjeto1()
{
	if (ClaseObjeto1)
	{
		FVector Location = GetActorLocation() + OffsetSpawn;

		GetWorld()->SpawnActor<AActor>(ClaseObjeto1, GetActorLocation(), GetActorRotation());
	}
}

void AMySpawnerActor::SpawnObjeto2()
{
	if (ClaseObjeto2)
	{
		FVector Location = GetActorLocation() + OffsetSpawn*2;
		GetWorld()->SpawnActor<AActor>(ClaseObjeto2, Location, GetActorRotation());
	}

}
void AMySpawnerActor::SpawnObjeto3()
{
	if (ClaseObjeto3)
	{
		FVector Location = GetActorLocation() + OffsetSpawn * 3;
		GetWorld()->SpawnActor<AActor>(ClaseObjeto3, Location, GetActorRotation());
	}
}
void AMySpawnerActor::Autodestruir()
{
	Destroy();
}
