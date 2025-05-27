// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject2.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AMyObject2::AMyObject2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyObject2::BeginPlay()
{
	Super::BeginPlay();

	if (SonidoAReproducir)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SonidoAReproducir, GetActorLocation());
	}
	

	
}

// Called every frame
void AMyObject2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

