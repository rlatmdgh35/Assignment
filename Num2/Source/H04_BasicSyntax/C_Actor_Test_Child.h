// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C_Actor_Test.h"
#include "C_Actor_Test_Child.generated.h"

/**
 * 
 */
UCLASS()
class H04_BASICSYNTAX_API AC_Actor_Test_Child : public AC_Actor_Test
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

};
