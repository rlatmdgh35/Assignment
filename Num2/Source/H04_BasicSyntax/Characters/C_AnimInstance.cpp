#include "C_AnimInstance.h"
#include "C_Player.h"
#include "Global.h"


void UC_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	C_Log::Log(TryGetPawnOwner());

	Player = Cast<AC_Player>(TryGetPawnOwner());

}



void UC_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);


	CheckNull(Player);

	Speed = Player->GetVelocity().Size2D();

	// TryGetPawnOwener();
}