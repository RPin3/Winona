// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinTrigger.generated.h"

UCLASS()
class PEARTANCARELOADED_API AWinTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AWinTrigger();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* TriggerBox;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
public:
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UUserWidget> VictoryScreenClass;

private:

	UPROPERTY()
	UUserWidget* VictoryScreenInstance;
};
