#pragma once

#include "CoreMinimal.h"
#include "Meshes/C_Movemeshes_Red.h"
#include "C_Movemeshes_Red_Ch2.generated.h"


UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes_Red_Ch2 : public AC_Movemeshes_Red
{
	GENERATED_BODY()

public:
	AC_Movemeshes_Red_Ch2();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void BeginOverlap();
	UFUNCTION()
		void EndOverlap();

	float CheckLife;

public:
	FORCEINLINE bool IsOverlap() { return bMove; }
	
};
