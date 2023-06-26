#include "C_Movemeshes.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"


AC_Movemeshes::AC_Movemeshes()
{
	C_Helpers::CreateSceneComponent<UStaticMeshComponent>(this, &StaticMesh, "StaticMesh");
	UStaticMesh* staticMesh;
	C_Helpers::GetAsset<UStaticMesh>(&staticMesh, "StaticMesh'/Game/StaticMesh/StaticMeshes/SM_Cube.SM_Cube'");
	StaticMesh->SetStaticMesh(staticMesh);
}

void AC_Movemeshes::BeginPlay()
{
	Super::BeginPlay();
}
