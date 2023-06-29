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
