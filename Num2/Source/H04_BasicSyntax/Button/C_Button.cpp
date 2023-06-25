#include "C_Button.h"
#include "Global.h"


AC_Button::AC_Button()
{
	C_Helpers::CreateSceneComponent<USceneComponent>(this, &Root, "Root");
	C_Helpers::CreateSceneComponent<UStaticMeshComponent>(this, &Cylinder, "Cylinder", Root);
	C_Helpers::CreateSceneComponent<UBoxComponent>(this, &BoxCollision, "BoxCollision", Root);


	UStaticMesh* staticmesh;

	C_Helpers::GetAsset<UStaticMesh>(&staticmesh, "StaticMesh'/Game/StaticMesh/StaticMeshes/SM_Cylinder.SM_Cylinder'");
	CheckNull(staticmesh);
	Cylinder->SetStaticMesh(staticmesh);
	Cylinder->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.05f));
	BoxCollision->SetRelativeScale3D(FVector(1.f, 1.f, 0.5f));
}

