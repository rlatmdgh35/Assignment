#include "C_Button_Blue.h"
#include "Global.h"


AC_Button_Blue::AC_Button_Blue()
{
	C_Helpers::GetAsset(&Material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Blue_Inst.MAT_Button_Blue_Inst'");
	CheckNull(Material);
	Cylinder->SetMaterial(0, Material);
}
