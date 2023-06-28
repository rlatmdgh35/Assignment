#include "C_Movemeshes_Red_Ch1.h"
#include "Global.h"


AC_Movemeshes_Red_Ch1::AC_Movemeshes_Red_Ch1()
{
	StaticMesh->SetRelativeScale3D(FVector(1.5f, 3.f, 0.1f));

}

void AC_Movemeshes_Red_Ch1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}