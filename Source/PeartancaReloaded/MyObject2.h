// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyObject2.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyObject2 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyObject2();

	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* SonidoAReproducir;

protected:
	virtual void BeginPlay() override;


};
