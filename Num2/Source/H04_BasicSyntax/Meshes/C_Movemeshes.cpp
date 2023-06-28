#include "C_Movemeshes.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"


AC_Movemeshes::AC_Movemeshes()
{
	PrimaryActorTick.bCanEverTick = true;

	C_Helpers::CreateSceneComponent<UStaticMeshComponent>(this, &StaticMesh, "StaticMesh");
	UStaticMesh* staticMesh;
	C_Helpers::GetAsset<UStaticMesh>(&staticMesh, "StaticMesh'/Game/StaticMesh/StaticMeshes/SM_Cube.SM_Cube'");
	StaticMesh->SetStaticMesh(staticMesh);
}

void AC_Movemeshes::BeginPlay()
{
	Super::BeginPlay();

	StartActorLocation = GetActorLocation();
}


float AC_Movemeshes::MoveValue(float DeltaTime, float FinishTime, float Length)
{
	DeltaSeconds += DeltaTime;
	float finishTime = FinishTime;
	float length = Length;
	float result, checkdirection, ReturnValue;
	bool bForward = true;

	result = fmodf(DeltaSeconds, finishTime);
	checkdirection = fmodf(DeltaSeconds / finishTime, 2);

	if (checkdirection <= 1)
		bForward = true;
	else
		bForward = false;


	if (bForward)
		ReturnValue = result * length / finishTime;
	else
		ReturnValue = length * (1 - result / finishTime);

	return ReturnValue;
}


void AC_Movemeshes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}