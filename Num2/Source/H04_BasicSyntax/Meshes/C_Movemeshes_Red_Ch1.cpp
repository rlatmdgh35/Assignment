#include "C_Movemeshes_Red_Ch1.h"
#include "Global.h"
#include "Button/C_Button_Red.h"

AC_Movemeshes_Red_Ch1::AC_Movemeshes_Red_Ch1()
{
	StaticMesh->SetRelativeScale3D(FVector(1.5f, 3.f, 0.1f));

}

void AC_Movemeshes_Red_Ch1::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC_Movemeshes_Red_Ch1::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC_Movemeshes_Red_Ch1::EndOverlap);

}

void AC_Movemeshes_Red_Ch1::BeginOverlap()
{
	bMove = true;
}

void AC_Movemeshes_Red_Ch1::EndOverlap()
{
	bMove = false;
}


void AC_Movemeshes_Red_Ch1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsOverlap())
	{
		FHitResult hitresult;
		Location.X = MoveValue(GetWorld()->GetDeltaSeconds(), 3.f, 350.f);
		Location.Z = MoveValue(GetWorld()->GetDeltaSeconds(), 3.f, 200.f);
	}

	SetActorLocation(StartActorLocation + Location);

}