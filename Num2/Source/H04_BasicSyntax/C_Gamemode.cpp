#include "C_Gamemode.h"
#include "Characters/C_Player.h"


AC_Gamemode::AC_Gamemode()
{
	ConstructorHelpers::FClassFinder<APawn> PawnAsset(TEXT("Blueprint'/Game/Player/BP_Player.BP_Player_C'"));
	if (PawnAsset.Succeeded())
		DefaultPawnClass = PawnAsset.Class;

}