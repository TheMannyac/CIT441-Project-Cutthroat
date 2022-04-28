// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTPRACTICE_API UCustomBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, Category = "Helper Functions")
			static void Print(FString text);

		UFUNCTION(BlueprintCallable, Category = "Helper Functions")
			static UActorComponent* SpawnActorComponent(TSubclassOf<UActorComponent> componentClass, AActor* owner);

		UFUNCTION(BlueprintCallable, Category = "Helper Functions")
			static USceneComponent* SpawnSceneComponent(TSubclassOf<USceneComponent> componentClass, AActor* owner, USceneComponent* attachTo = nullptr);

		UFUNCTION(BlueprintCallable, Category = "Helper Functions")
			static void SortByBoundsSize(UPARAM(ref) TArray<AActor*>& arr);

		UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Helper Functions")//BlueprintPure means no white execution pin
			static bool HasComponent(const AActor* actor, const FName tag, const TSubclassOf<UActorComponent> componentClass);

};

//typedef (or alias in other languages)
//gives a data type a 'nickname' so you can use that (shorter) name instead.
typedef UCustomBlueprintFunctionLibrary Helpers;

