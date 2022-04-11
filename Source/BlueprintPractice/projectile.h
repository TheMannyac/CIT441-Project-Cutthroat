// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include <BlueprintPractice/base_dt.h>

#include "projectile.generated.h"

UCLASS(Abstract, Blueprintable)
class BLUEPRINTPRACTICE_API Aprojectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aprojectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Components
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* Projectile;
	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int baseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<Ubase_dt> PrimaryDamageType;
};
