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

	TArray<AActor*> actor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Button_Red::StaticClass(), actor);
	CheckFalse(actor.Num() > 0);

	AC_Button_Red* button = Cast<AC_Button_Red>(actor[0]);
	CheckNull(button);

	button->ActorBeginOverlap.BindUFunction(this, "BeginOverlap");
	button->ActorEndOverlap.BindUFunction(this, "EndOverlap");




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
		Location.X = MoveValue(GetWorld()->GetDeltaSeconds(), 3.f, 350.f);
		Location.Z = MoveValue(GetWorld()->GetDeltaSeconds(), 3.f, 200.f);
	}

	SetActorLocation(StartActorLocation + Location);

}