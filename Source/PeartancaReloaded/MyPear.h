// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "MyPear.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyPear : public APawn
{
	GENERATED_BODY()


protected:

public:
	AMyPear();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void VerticalAxis(float Value);
	void HorizontalAxis(float Value);
	UPROPERTY(EditAnywhere)
	float velocity;
	UPROPERTY(EditAnywhere)
	float rotationVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Collision")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> spawnObject;

	void FireProjectile();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	AActor* RespawnTarget;

	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float DamageAmount);

	FTimerHandle RespawnTimerHandle;

	FVector InitialLocation;
	FRotator InitialRotation;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Keys")
	int KeyCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ammo")
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ammo")
	int32 MaxAmmo;

	UFUNCTION(BlueprintCallable)
	void ReloadAmmo();

	
	virtual void BeginPlay() override;
};

