#include "C_Button_Blue_Overlap.h"
#include "Global.h"
#include "GameFramework/Character.h"


void AC_Button_Blue_Overlap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC_Button_Blue_Overlap::BeginOverlap);
}

void AC_Button_Blue_Overlap::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);
	CheckNull(otherCharacter);

	if (OnBeginOverlap.IsBound())
	{
		OnBeginOverlap.Execute();
	}
}