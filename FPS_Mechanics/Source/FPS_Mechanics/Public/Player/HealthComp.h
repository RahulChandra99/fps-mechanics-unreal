// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComp.generated.h"

class UDamageType;
class AController;
class AActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, Health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDied);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_MECHANICS_API UHealthComp : public UActorComponent
{
	GENERATED_BODY()

	float CurrentHealth;

	UFUNCTION()
	void OnOwnerTakenDamage(AActor* DamagedActor, float Damage, const  UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);


public:	
	// Sets default values for this component's properties
	UHealthComp();

	/*Max Player Health*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxHealth;

	/*Starting Player Health*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float StartingHealth;

	UFUNCTION(BlueprintPure, Category="Health")
	float GetCurrentHealth();

	UFUNCTION(BlueprintPure, Category="Health")
	bool GetIsDead();

	UPROPERTY(BlueprintAssignable, Category= "Health")
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDied OnDied;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
