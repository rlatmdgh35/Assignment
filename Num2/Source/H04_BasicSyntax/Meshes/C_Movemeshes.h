#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Movemeshes.generated.h"

UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Movemeshes();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;

};
