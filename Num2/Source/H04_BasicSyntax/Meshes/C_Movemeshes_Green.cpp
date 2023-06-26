#include "C_Movemeshes_Green.h"
#include "Global.h"


AC_Movemeshes_Green::AC_Movemeshes_Green()
{
	UMaterialInstanceConstant* material;
	C_Helpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Green_Inst.MAT_Button_Green_Inst'");
	CheckNull(material);
	StaticMesh->SetMaterial(0, material);
	StaticMesh->SetRelativeScale3D(FVector(1.5f, 3.f, 0.1f));
}
