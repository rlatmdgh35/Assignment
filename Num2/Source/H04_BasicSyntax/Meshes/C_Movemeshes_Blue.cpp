#include "C_Movemeshes_Blue.h"
#include "Global.h"
#include "Button/C_Button_Blue_Overlap.h"
#include "Button/C_Button_Blue_Reset.h"


AC_Movemeshes_Blue::AC_Movemeshes_Blue()
{
	C_Helpers::GetAsset(&Material, "MaterialInstanceConstant'/Game/StaticMesh/Material/MAT_Button_Blue_Inst.MAT_Button_Blue_Inst'");
	CheckNull(Material);
	StaticMesh->SetMaterial(0, Material);

	StaticMesh->SetRelativeScale3D(FVector(2.f, 2.f, 0.35f));
}

void AC_Movemeshes_Blue::BeginPlay()
{
	Super::BeginPlay();

	bMove = true;

	TArray<AActor*> overlapActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Button_Blue_Overlap::StaticClass(), overlapActors);
	CheckFalse(overlapActors.Num() > 0);

	AC_Button_Blue_Overlap* overlapButton = Cast<AC_Button_Blue_Overlap>(overlapActors[0]);
	CheckNull(overlapButton);

	
	TArray<AActor*> resetActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Button_Blue_Reset::StaticClass(), resetActors);
	CheckFalse(resetActors.Num() > 0);

	AC_Button_Blue_Reset* resetButton = Cast<AC_Button_Blue_Reset>(resetActors[0]);
	CheckNull(resetButton);
	

	overlapButton->OnBeginOverlap.BindUFunction(this, "DoFall");
	resetButton->OnBeginOverlap.BindUFunction(this, "Reset");

}

void AC_Movemeshes_Blue::DoFall()
{
	bMove = false;
	StaticMesh->SetSimulatePhysics(true);
}

void AC_Movemeshes_Blue::Reset()
{
	if (bMove == false)
	{
		StaticMesh->SetSimulatePhysics(false);
		SetActorLocationAndRotation(FVector(-350.f, -350.f, 500), FRotator::ZeroRotator);
		DeltaSeconds = 0;
	}
	bMove = true;
}


void AC_Movemeshes_Blue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (bMove)
	{
		Location.Y = MoveValue(GetWorld()->GetDeltaSeconds(), 7, 700);
		SetActorLocation(StartActorLocation + Location);
	}
}

