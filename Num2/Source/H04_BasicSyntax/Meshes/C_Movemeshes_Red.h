#pragma once

#include "CoreMinimal.h"
#include "Meshes/C_Movemeshes.h"
#include "C_Movemeshes_Red.generated.h"


UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes_Red : public AC_Movemeshes
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AC_Movemeshes_Red();

};
