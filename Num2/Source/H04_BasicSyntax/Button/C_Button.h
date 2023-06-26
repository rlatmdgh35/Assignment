#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Button.generated.h"

UCLASS()
class H04_BASICSYNTAX_API AC_Button : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Button();

protected:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Cylinder;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(VisibleDefaultsOnly)
		class UMaterialInstanceConstant* Material;
};
