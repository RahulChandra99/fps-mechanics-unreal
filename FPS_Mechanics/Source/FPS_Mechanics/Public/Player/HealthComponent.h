// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

UCLASS()
class FPS_MECHANICS_API AHealthComponent : public AActor
{
	GENERATED_BODY()

	float CurrentHealth;
	
public:	
	// Sets default values for this actor's properties
	AHealthComponent();

	/*Max Player Health*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxHealth;

	/*Starting Player Health*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float StartingHealth;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
