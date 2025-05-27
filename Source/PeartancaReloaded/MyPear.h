// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPear.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyPear : public APawn
{
	GENERATED_BODY()


protected:

public:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void VerticalAxis(float Value);
	void HorizontalAxis(float Value);
	UPROPERTY(EditAnywhere)
	float velocity;
	UPROPERTY(EditAnywhere)
	float rotationVelocity;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> spawnObject;

	void FireProjectile();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	AActor* RespawnTarget;

	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float DamageAmount);


};

