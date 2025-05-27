// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject3.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AMyObject3::AMyObject3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyObject3::BeginPlay()
{
	Super::BeginPlay();

	if (SonidoInicio)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SonidoInicio, GetActorLocation());
	}
	
}

// Called every frame
void AMyObject3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Direccion = GetActorForwardVector();
	SetActorLocation(GetActorLocation() + Direccion * VelocidadMovimiento * DeltaTime);
	AddActorLocalRotation(VelocidadRotacion * DeltaTime);

}

