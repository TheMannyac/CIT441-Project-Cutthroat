// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomBlueprintFunctionLibrary.h"
#include "Engine/Engine.h" 

void UCustomBlueprintFunctionLibrary::Print(FString text)
{
	//Output Log
	UE_LOG(LogTemp, Warning, TEXT("%s"), *text);//This is the 'Debug.Log' or 'printf' or 'cout <<' of UE4 C++.

	//Print String to Screen
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("%s"), *text));//This is like a PrintString blueprint node.
}

//TSubclassOf means only ActorComponents or derivative classes of ActorComponents can be used.
UActorComponent* UCustomBlueprintFunctionLibrary::SpawnActorComponent(TSubclassOf<UActorComponent> componentClass, AActor* owner)
{
	if (!componentClass || !owner)
	{
		Print("SpawnActorComponent class or owner was null");
		return nullptr;
	}

	//This creates an object
	UActorComponent* newComp = NewObject<UActorComponent>(owner, componentClass.Get());

	//This makes it appear in the editor/game
	newComp->RegisterComponent();

	return newComp;
}

USceneComponent* UCustomBlueprintFunctionLibrary::SpawnSceneComponent(TSubclassOf<USceneComponent> componentClass, AActor* owner, USceneComponent* attachTo)
{
	if (!componentClass || !owner)
	{
		Print("SpawnSceneComponent class or owner was null");
		return nullptr;
	}

	USceneComponent* newComp = NewObject<USceneComponent>(owner, componentClass.Get());

	newComp->RegisterComponent();

	if (!attachTo)
		attachTo = owner->GetRootComponent();

	newComp->AttachToComponent(attachTo,
		FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			false));

	return newComp;
}

bool UCustomBlueprintFunctionLibrary::HasComponent(const AActor* actor, const FName tag, const TSubclassOf<UActorComponent> componentClass)
{
	if (!actor)
		return false;

	TArray<UActorComponent*> components = actor->GetComponentsByTag(componentClass, tag);
	if (components.Num() > 0)
		return true;
	return false;
}

//Just an example of how you can sort arrays by some property.
//Normally parameters passed by reference in UE4 C++ will become output pins.
//UPARAM(ref) forces arr to be an input pin in a blueprint node, instead of an output pin.
//TArray<int> = vector<int> (C#/Java) list<int>
void UCustomBlueprintFunctionLibrary::SortByBoundsSize(UPARAM(ref) TArray<AActor*>& arr)
{
	Algo::Sort(arr, [](AActor* a1, AActor* a2) { return a1->GetSimpleCollisionRadius() < a2->GetSimpleCollisionRadius(); });
}

