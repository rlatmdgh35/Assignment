#pragma once

#include "CoreMinimal.h"
#include "Meshes/C_Movemeshes.h"
#include "C_Movemeshes_Blue.generated.h"

UCLASS()
class H04_BASICSYNTAX_API AC_Movemeshes_Blue : public AC_Movemeshes
{
	GENERATED_BODY()

public:
	AC_Movemeshes_Blue();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
public:
	FORCEINLINE bool IsMove() { return bMove; }


private:
	UFUNCTION()
		void Reset();
	
	UFUNCTION()
		void DoFall();


private:
	UPROPERTY(VisibleDefaultsOnly)
		class UMaterialInstanceConstant* Material;
};
