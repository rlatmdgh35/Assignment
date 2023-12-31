#pragma once

#include "CoreMinimal.h"
#include "Button/C_Button.h"
#include "C_Button_Blue.generated.h"

DECLARE_DELEGATE(FOnBeginOverlap);

UCLASS()
class H04_BASICSYNTAX_API AC_Button_Blue : public AC_Button
{
	GENERATED_BODY()

public:
	AC_Button_Blue();

protected:
	virtual void BeginPlay() override;

public:
	FOnBeginOverlap OnBeginOverlap;
};

