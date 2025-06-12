#include "MyPear.h"

#include "MainHUDWidget.h"
#include "MyGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MiPlayerController.h"


AMyPear::AMyPear()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CurrentAmmo = 10;
	MaxAmmo = 10;

}

void AMyPear::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("Vertical", this, &AMyPear::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &AMyPear::HorizontalAxis);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AMyPear::FireProjectile);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AMyPear::ReloadAmmo);

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
	
		if (CurrentAmmo > 0)
		{
			GetWorld()->SpawnActor<AActor>(spawnObject, GetActorLocation(), GetActorRotation());
			CurrentAmmo--;

			APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			if (PC)
			{
				AMiPlayerController* MyPC = Cast<AMiPlayerController>(PC);
				if (MyPC && MyPC->MainHUD)
				{
					MyPC->MainHUD->UpdateAmmo(CurrentAmmo, MaxAmmo);
				}
			}
		}

}

void AMyPear::ReceiveDamage(float DamageAmount)
{
	Health -= DamageAmount;


	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		AMiPlayerController* MyPC = Cast<AMiPlayerController>(PC);
		if (MyPC && MyPC->MainHUD)
		{
			MyPC->MainHUD->UpdateHealth(Health / 100.0f);  
		}
	}

	if (Health <= 0.0f)
	{
		Destroy();
	}
}

void AMyPear::ReloadAmmo()
{
	CurrentAmmo = MaxAmmo;

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		AMiPlayerController* MyPC = Cast<AMiPlayerController>(PC);
		if (MyPC && MyPC->MainHUD)
		{
			MyPC->MainHUD->UpdateAmmo(CurrentAmmo, MaxAmmo);
		}
	}
}


void AMyPear::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		AMiPlayerController* MyPC = Cast<AMiPlayerController>(PC);
		if (MyPC && MyPC->MainHUD)
		{
			MyPC->MainHUD->UpdateAmmo(CurrentAmmo, MaxAmmo);
			MyPC->MainHUD->UpdateHealth(Health / 100.0f);
		}
	}

	InitialLocation = GetActorLocation();
	InitialRotation = GetActorRotation();
}
