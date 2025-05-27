#include "MyPear.h"

void AMyPear::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("Vertical", this, &AMyPear::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &AMyPear::HorizontalAxis);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AMyPear::FireProjectile);
}

void AMyPear::VerticalAxis(float Value)
{
	float deltatime = GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(Value * velocity * deltatime, 0, 0));
}

void AMyPear::HorizontalAxis(float Value)
{
	float deltatime = GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(0, Value * rotationVelocity * deltatime, 0));
}

void AMyPear::FireProjectile()
{
	GetWorld()->SpawnActor<AActor>(spawnObject, GetActorLocation(), GetActorRotation());
}

void AMyPear::ReceiveDamage(float DamageAmount)
{
	Health -= DamageAmount;

	if (GEngine)
	{
		FString Msg = FString::Printf(TEXT("¡Daño recibido! Vida restante: %.1f"), Health);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, Msg);
	}

	if (Health <= 0.0f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("GAME OVER"));
		}

		Destroy(); // 💥 Destruye el actor
	}
}
