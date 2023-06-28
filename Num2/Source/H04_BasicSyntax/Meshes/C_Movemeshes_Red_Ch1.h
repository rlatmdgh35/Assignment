#pragma once

#include "CoreMinimal.h"
#include "Meshes/C_Movemeshes_Red.h"
#include "C_Movemeshes_Red_Ch1.generated.h"


UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes_Red_Ch1 : public AC_Movemeshes_Red
{
	GENERATED_BODY()

public:
	AC_Movemeshes_Red_Ch1();
	
public:
	virtual void Tick(float DeltaTime) override;



};
