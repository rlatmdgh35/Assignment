#include "C_Button_Blue_Reset.h"
#include "Global.h"
#include "GameFramework/Character.h"


void AC_Button_Blue_Reset::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC_Button_Blue_Reset::BeginOverlap);
}

void AC_Button_Blue_Reset::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);
	CheckNull(otherCharacter);

	if (OnBeginOverlap.IsBound())
	{
		OnBeginOverlap.Execute();
	}
}