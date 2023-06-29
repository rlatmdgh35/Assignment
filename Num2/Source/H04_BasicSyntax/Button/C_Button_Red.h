#pragma once

#include "CoreMinimal.h"
#include "Button/C_Button.h"
#include "C_Button_Red.generated.h"

DECLARE_DELEGATE(FBoxBeginOverlap);
DECLARE_DELEGATE(FBoxEndOverlap);

UCLASS()
class H04_BASICSYNTAX_API AC_Button_Red : public AC_Button
{
	GENERATED_BODY()

public:
	AC_Button_Red();

public:
	FBoxBeginOverlap OnBeginOverlap;
	FBoxEndOverlap OnEndOverlap;


public:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void EndOverlap(AActor* OverlappedActor, AActor* OtherActor);


};
