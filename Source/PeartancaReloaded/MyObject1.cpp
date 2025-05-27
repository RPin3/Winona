#include "MyObject1.h"

AMyObject1::AMyObject1()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMyObject1::BeginPlay()
{
	Super::BeginPlay();


	
}

void AMyObject1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Movimiento = GetActorForwardVector() * Velocidad * DeltaTime;
	AddActorWorldOffset(Movimiento);
}

