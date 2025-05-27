// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyObject3.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyObject3 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyObject3();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float VelocidadMovimiento = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Rotación")
	FRotator VelocidadRotacion = FRotator(0.f, 90.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* SonidoInicio;
protected:
	virtual void BeginPlay() override;


};
