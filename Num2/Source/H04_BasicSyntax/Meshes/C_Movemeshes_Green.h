#pragma once

#include "CoreMinimal.h"
#include "Meshes/C_Movemeshes.h"
#include "C_Movemeshes_Green.generated.h"


UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes_Green : public AC_Movemeshes
{
	GENERATED_BODY()
	
public:
	AC_Movemeshes_Green();

public:
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void BeginOverlap();

	UFUNCTION()
		void EndOverlap();

	bool IsMove;

	float MoveValue(float DeltaTime, float FinishTime, float Length);



};
