#include "C_Button_Red.h"
#include "Meshes/C_Movemeshes_Blue.h"
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
	OtherCharacter = Cast<ACharacter>(OtherActor);
	OtherMesh = Cast<AC_Movemeshes_Blue>(OtherActor);

	if (!!OtherCharacter)
		CharacterBeginOverlap();

	else if (!!OtherMesh)
		MeshBeginOverlap();

	else
		C_Log::Print("else");


}

void AC_Button_Red::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	OtherCharacter = Cast<ACharacter>(OtherActor);
	OtherMesh = Cast<AC_Movemeshes_Blue>(OtherActor);


	if (!!OtherCharacter)
		CharacterEndOverlap();

	else if (!!OtherMesh)
		MeshEndOverlap();

	else
		C_Log::Print("else");
}

void AC_Button_Red::CharacterBeginOverlap()
{
	if (ActorBeginOverlap.IsBound())
		ActorBeginOverlap.Execute();
}

void AC_Button_Red::CharacterEndOverlap()
{
	if (ActorEndOverlap.IsBound())
		ActorEndOverlap.Execute();
}

void AC_Button_Red::MeshBeginOverlap()
{
	if (StaticMeshBeginOverlap.IsBound())
		StaticMeshBeginOverlap.Execute();

}

void AC_Button_Red::MeshEndOverlap()
{
	if (StaticMeshEndOverlap.IsBound())
		StaticMeshEndOverlap.Execute();
}