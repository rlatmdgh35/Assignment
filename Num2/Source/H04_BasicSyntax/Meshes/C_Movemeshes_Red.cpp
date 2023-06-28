#include "C_Movemeshes_Red.h"
#include "Global.h"


AC_Movemeshes_Red::AC_Movemeshes_Red()
{
	UMaterialInstanceConstant* material;
	C_Helpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Red_Inst.MAT_Button_Red_Inst'");
	CheckNull(material);
	StaticMesh->SetMaterial(0, material);
}

void AC_Movemeshes_Red::BeginPlay()
{
	Super::BeginPlay();
}

void AC_Movemeshes_Red::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}