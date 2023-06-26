#include "C_Button_Green.h"
#include "Global.h"


AC_Button_Green::AC_Button_Green()
{
	C_Helpers::GetAsset(&Material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Green_Inst.MAT_Button_Green_Inst'");
	CheckNull(Material);
	Cylinder->SetMaterial(0, Material);
}

