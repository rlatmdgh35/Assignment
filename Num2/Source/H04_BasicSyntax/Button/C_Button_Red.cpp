#include "C_Button_Red.h"
#include "Global.h"
#include "Meshes/C_Movemeshes.h"

AC_Button_Red::AC_Button_Red()
{
	C_Helpers::GetAsset(&Material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Red_Inst.MAT_Button_Red_Inst'");
	CheckNull(Material);
	Cylinder->SetMaterial(0, Material);
}

void AC_Button_Red::BeginPlay()
{
	Super::BeginPlay();


	



}
