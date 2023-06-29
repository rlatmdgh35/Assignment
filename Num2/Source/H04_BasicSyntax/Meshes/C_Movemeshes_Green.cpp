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

void AC_Movemeshes_Green::BeginOverlap()
{
	C_Log::Print("True");
	bMove = true;
}

void AC_Movemeshes_Green::EndOverlap()
{
	C_Log::Print("False");
	bMove = false;
}

void AC_Movemeshes_Green::BeginPlay()
{
	Super::BeginPlay();
}

void AC_Movemeshes_Green::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	if (true)
	{
		FHitResult hitresult;
		Location.Z = MoveValue(GetWorld()->GetDeltaSeconds(), 3.f, 170.f);
	}

	SetActorLocation(StartActorLocation + Location);
}