#pragma once

#include "CoreMinimal.h"
#include "Button/C_Button_Blue.h"
#include "C_Button_Blue_Reset.generated.h"


UCLASS()
class H04_BASICSYNTAX_API AC_Button_Blue_Reset : public AC_Button_Blue
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
