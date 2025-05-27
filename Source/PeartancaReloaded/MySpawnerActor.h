// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpawnerActor.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMySpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySpawnerActor();
	virtual void BeginPlay() override;


	void SpawnObjeto1();
	void SpawnObjeto2();
	void SpawnObjeto3();
	void Autodestruir();

	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<AActor> ClaseObjeto1;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<AActor> ClaseObjeto2;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<AActor> ClaseObjeto3;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	float TiempoEntreSpawns = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	FVector OffsetSpawn = FVector(100.f, 0.f, 0.f); // Separación entre objetos

	FTimerHandle TimerHandle1;
	FTimerHandle TimerHandle2;
	FTimerHandle TimerHandle3;
	FTimerHandle TimerHandleDestruir;

};
