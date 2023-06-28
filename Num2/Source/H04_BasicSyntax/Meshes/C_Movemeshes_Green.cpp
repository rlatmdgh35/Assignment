#include "C_Movemeshes_Green.h"
#include "Global.h"
#include "Button/C_Button_Green.h"


AC_Movemeshes_Green::AC_Movemeshes_Green()
{
	PrimaryActorTick.bCanEverTick = true;

	UMaterialInstanceConstant* material;
	C_Helpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Green_Inst.MAT_Button_Green_Inst'");
	CheckNull(material);
	StaticMesh->SetMaterial(0, material);
	StaticMesh->SetRelativeScale3D(FVector(1.5f, 3.f, 0.1f));

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Button_Green::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	AC_Button_Green* button = Cast<AC_Button_Green>(actors[0]);
	CheckNull(button);

	button->OnBeginOverlap.BindUFunction(this, "BeginOverlap");
	button->OnEndOverlap.BindUFunction(this, "EndOverlap");


}

void AC_Movemeshes_Green::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Button_Green::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);


	AC_Button_Green* button = Cast<AC_Button_Green>(actors[0]);
	CheckNull(button);

	button->OnBeginOverlap.BindUFunction(this, "BeginOverlap");
	button->OnEndOverlap.BindUFunction(this, "EndOverlap");
}


void AC_Movemeshes_Green::BeginOverlap()
{
	bMove = true;
	C_Log::Print("True");
}

void AC_Movemeshes_Green::EndOverlap()
{
	bMove = false;
	C_Log::Print("False");
}



float AC_Movemeshes_Green::MoveValue(float DeltaTime, float FinishTime, float Length)
{
	float delta = DeltaTime;
	float finishTime = FinishTime;
	float result;
	float checkdirection;
	float length = Length;
	float ReturnValue;
	bool bForward;

	
	delta += DeltaTime;
	result = fmodf(delta, finishTime);
	checkdirection = fmodf(delta / finishTime, 2);

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

void AC_Movemeshes_Green::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector location = GetActorLocation();
	FHitResult hitresult;


	if (IsOverlap())
	{
		C_Log::Print("IsMove");
		location.Z = MoveValue(DeltaTime, 3, 170);
	}
	
	K2_SetActorRelativeLocation(location, false, hitresult, false);
}