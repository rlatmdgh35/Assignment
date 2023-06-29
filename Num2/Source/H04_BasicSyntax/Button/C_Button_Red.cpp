#include "C_Button_Red.h"
#include "Global.h"
#include "GameFramework/Character.h"

AC_Button_Red::AC_Button_Red()
{
	C_Helpers::GetAsset(&Material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Red_Inst.MAT_Button_Red_Inst'");
	CheckNull(Material);
	Cylinder->SetMaterial(0, Material);
}

void AC_Button_Red::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC_Button_Red::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC_Button_Red::EndOverlap);

	

}

void AC_Button_Red::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);
	CheckNull(otherCharacter);


	if (ActorBeginOverlap.IsBound())
		ActorBeginOverlap.Execute();
}

void AC_Button_Red::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ACharacter* otherCharacter = Cast<ACharacter>(OtherActor);
	CheckNull(otherCharacter);

	if (ActorEndOverlap.IsBound())
		ActorEndOverlap.Execute();
}
