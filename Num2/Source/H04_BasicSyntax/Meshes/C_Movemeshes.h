#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Global.h"
#include "C_Movemeshes.generated.h"

UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Movemeshes();

public:
	FVector StartActorLocation;
	FVector Location = FVector(0, 0, 0);
	float DeltaSeconds = 0;
	bool bMove;

	float MoveValue(float DeltaTime, float FinishTime, float Length);


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;

};
