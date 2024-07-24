// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UArrowComponent;
class ABulletBase;
class USceneComponent;

UCLASS()
class FPSSYSTEM_API AWeaponBase : public AActor
{
	GENERATED_BODY()
private:

	FTimerHandle ReFireHandle;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon",meta=(AllowPrivateAccess = true))
	USceneComponent* RootComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon",meta=(AllowPrivateAccess = true))
	UArrowComponent* MuzzlePoint;

	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	TSubclassOf<ABulletBase> BulletClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	float ReFireRate = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	float RemainingAmmo = 9999;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon")
	bool bFullyAutomatic = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	FTransform CustomTransform;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, Category="Weapon")
	void StartFiring();
	
	UFUNCTION(BlueprintNativeEvent, Category="Weapon")
	void StopFiring();

	UFUNCTION(BlueprintImplementableEvent, Category="Weapon")
	void OnEquipped();

	UFUNCTION(BlueprintImplementableEvent, Category="Weapon")
	void OnUnEquipped();

	UFUNCTION(BlueprintImplementableEvent, Category="Weapon")
	void OnFiredRound();

	UFUNCTION()
	FTransform GetCustomTransform();

private:
	void FireRound();
};
