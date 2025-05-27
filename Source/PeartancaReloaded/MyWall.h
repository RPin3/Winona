// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyWall.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyWall : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyWall();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* CollisionBox;	

	UPROPERTY(EditAnywhere)
	float Health;
protected:
	virtual void BeginPlay() override;
	
};
