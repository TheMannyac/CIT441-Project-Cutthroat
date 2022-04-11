// Fill out your copyright notice in the Description page of Project Settings.


#include "projectile.h"


// Sets default values
Aprojectile::Aprojectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//Create Components
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	Projectile->InitialSpeed = 3000;
	Projectile->MaxSpeed = 3000;

	//Default Variables
	PrimaryDamageType = Ubase_dt::StaticClass();
	baseDamage = 1;

	InitialLifeSpan = 5;
}

// Called when the game starts or when spawned
void Aprojectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aprojectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}