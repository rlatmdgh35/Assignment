#include "C_Player.h"
#include "Global.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/C_AnimInstance.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"





void AC_Player::OnHorizontalLook(float Axis)
{
	AddControllerYawInput(Axis);
}

void AC_Player::OnVerticalLook(float Axis)
{
	AddControllerPitchInput(Axis);
}

void AC_Player::OnSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

void AC_Player::OffSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}


AC_Player::AC_Player()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Scene Component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Components Settings
	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if(MeshAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, 270, 0));


	ConstructorHelpers::FClassFinder<UAnimInstance> AnimAsset(TEXT("AnimBlueprint'/Game/Player/ABP_Player.ABP_Player_C'"));
	if (AnimAsset.Succeeded())
		GetMesh()->SetAnimInstanceClass(AnimAsset.Class);

	// SpringArm
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetRelativeLocation(FVector(0, 0, 135));
	SpringArm->TargetArmLength = 250.f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;

	// Camera
	Camera->SetupAttachment(SpringArm);
	Camera->SetRelativeRotation(FRotator(-10.f, 0, 0));

	//Movement
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}

void AC_Player::BeginPlay()
{
	Super::BeginPlay();
	
	// Get Dynamic Materials
	UMaterialInstanceConstant* bodyMaterial;
	C_Helpers::AssetDynamic<UMaterialInstanceConstant>(&bodyMaterial, "MaterialInstanceConstant'/Game/Character/Materials/M_UE4Man_Body_Inst.M_UE4Man_Body_Inst'");
	
	UMaterialInstanceConstant* logoMaterial;
	C_Helpers::AssetDynamic<UMaterialInstanceConstant>(&logoMaterial, "MaterialInstanceConstant'/Game/Character/Materials/M_UE4Man_ChestLogo.M_UE4Man_ChestLogo'");

	// Create Dynamic Material
	BodyMaterial = UMaterialInstanceDynamic::Create(bodyMaterial, nullptr);
	LogoMaterial = UMaterialInstanceDynamic::Create(logoMaterial, nullptr);

	// Set Dynamic Material
	GetMesh()->SetMaterial(0, BodyMaterial);
	GetMesh()->SetMaterial(1, LogoMaterial);




}

void AC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



	PlayerInputComponent->BindAxis("MoveForward", this, &AC_Player::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AC_Player::OnMoveRight);

	PlayerInputComponent->BindAxis("HorizontalLook", this, &AC_Player::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &AC_Player::OnVerticalLook);

	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AC_Player::OnSprint);
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &AC_Player::OffSprint);
}


void AC_Player::OnMoveForward(float Axis)
{
	FRotator Rotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector Direction = FQuat(Rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(Direction, Axis);
}

void AC_Player::OnMoveRight(float Axis)
{
	FRotator Rotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector Direction = FQuat(Rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(Direction, Axis);
}


void AC_Player::SetPlayerColor(FLinearColor InBodyColor, FLinearColor InLogoColor)
{
	BodyMaterial->SetVectorParameterValue("BodyColor", InBodyColor);
	LogoMaterial->SetVectorParameterValue("BodyColor", InLogoColor);
}

void AC_Player::SetResetColor()
{
	FLinearColor origin = FLinearColor(0.450980f, 0.403922f, 0.360784f);
	SetPlayerColor(origin, origin);
}
