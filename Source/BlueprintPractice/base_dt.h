// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"

#include "base_dt.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTPRACTICE_API Ubase_dt : public UDamageType
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Ubase_dt();

public:
	//Set default values
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText deathMessage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AController* instagator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* causer;
};
