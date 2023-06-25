#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Player.generated.h"

UCLASS()
class H04_BASICSYNTAX_API AC_Player : public ACharacter
{
	GENERATED_BODY()

public:
	AC_Player();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable)
		void SetPlayerColor(FLinearColor InBodyColor, FLinearColor InLogoColor);

	UFUNCTION(BlueprintCallable)
		void SetResetColor();



// Axis Events
private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);
	
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

// Action Events
private:
	void OnSprint();
	void OffSprint();


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;

private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;



};



