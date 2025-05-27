#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyObject1.generated.h"

UCLASS()
class PEARTANCARELOADED_API AMyObject1 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyObject1();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float Velocidad = 200.0f;



protected:
	virtual void BeginPlay() override;
	
};
