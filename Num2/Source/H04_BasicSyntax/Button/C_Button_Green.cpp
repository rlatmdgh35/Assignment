#include "C_Button_Green.h"
#include "Global.h"
#include "GameFramework/Character.h"

AC_Button_Green::AC_Button_Green()
{
	C_Helpers::GetAsset(&Material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Green_Inst.MAT_Button_Green_Inst'");
	CheckNull(Material);
	Cylinder->SetMaterial(0, Material);
}

void AC_Button_Green::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC_Button_Green::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC_Button_Green::EndOverlap);
}

void AC_Button_Green::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);
	CheckNull(otherCharacter);
	C_Log::Print("BeginOverlap");

	if (OnBeginOverlap.IsBound())
	{
		C_Log::Print("BeginExecute");
		OnBeginOverlap.Execute();
	}
	else
		C_Log::Print("Begin Not Bound");
}

void AC_Button_Green::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);
	CheckNull(otherCharacter);
	C_Log::Print("EndOverlap");

	if (OnEndOverlap.IsBound())
	{
		C_Log::Print("EndExecute");
		OnEndOverlap.Execute();
	}
	else
		C_Log::Print("End Not Bound");
}