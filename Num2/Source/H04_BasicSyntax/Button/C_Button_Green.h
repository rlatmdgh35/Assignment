#pragma once

#include "CoreMinimal.h"
#include "Button/C_Button.h"
#include "C_Button_Green.generated.h"

DECLARE_DELEGATE(FBoxBeginOverlap);
DECLARE_DELEGATE(FBoxEndOverlap);


UCLASS()
class H04_BASICSYNTAX_API AC_Button_Green : public AC_Button
{
	GENERATED_BODY()

public:
	AC_Button_Green();

public:
	virtual void BeginPlay() override;

public:
	FBoxBeginOverlap OnBeginOverlap;
	FBoxEndOverlap OnEndOverlap;

private:
	UFUNCTION()
		void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void EndOverlap(AActor* OverlappedActor, AActor* OtherActor);


};
