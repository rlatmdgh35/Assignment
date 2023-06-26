#pragma once

#include "CoreMinimal.h"
#include "Button/C_Button.h"
#include "C_Button_Red.generated.h"


UCLASS()
class H04_BASICSYNTAX_API AC_Button_Red : public AC_Button
{
	GENERATED_BODY()

public:
	AC_Button_Red();

public:
	virtual void BeginPlay() override;
	
private:
	class AC_Movemeshes* Child[2];
};
