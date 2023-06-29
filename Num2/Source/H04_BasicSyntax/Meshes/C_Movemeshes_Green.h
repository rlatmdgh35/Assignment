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

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void BeginOverlap();
	UFUNCTION()
		void EndOverlap();

public:
	FORCEINLINE bool IsOverlap() { return bMove; }
};
