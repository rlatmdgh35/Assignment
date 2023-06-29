#include "C_Movemeshes_Red_Ch2.h"
#include "Button/C_Button_Red.h"
#include "Global.h"


AC_Movemeshes_Red_Ch2::AC_Movemeshes_Red_Ch2()
{
	StaticMesh->SetRelativeScale3D(FVector(1.5f, 3.f, 0.1f));

}

void AC_Movemeshes_Red_Ch2::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> actor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Button_Red::StaticClass(), actor);
	CheckFalse(actor.Num() > 0);

	AC_Button_Red* button = Cast<AC_Button_Red>(actor[0]);
	CheckNull(button);

	button->StaticMeshBeginOverlap.BindUFunction(this, "BeginOverlap");
	button->StaticMeshEndOverlap.BindUFunction(this, "EndOverlap");
}

void AC_Movemeshes_Red_Ch2::BeginOverlap()
{
	bMove = true;
}

void AC_Movemeshes_Red_Ch2::EndOverlap()
{
	bMove = false;
}


void AC_Movemeshes_Red_Ch2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsOverlap())
	{
		float checkLife = GetWorld()->GetDeltaSeconds();
		checkLife += checkLife;
		if (checkLife < 13.f)
		{
			Location.Z = MoveValue(GetWorld()->GetDeltaSeconds(), 6.5f, -650.f);
			SetActorLocation(StartActorLocation + Location);
		}
		else
		{
			DeltaTime = 0.f;
			SetActorLocation(FVector(-1400.f, 0.f, 820.f));
		}
		
	}

}