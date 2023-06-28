// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Actor_Test.h"
#include "Global.h"

// Sets default values
AC_Actor_Test::AC_Actor_Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_Actor_Test::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_Actor_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	C_Log::Print("Test");

}

