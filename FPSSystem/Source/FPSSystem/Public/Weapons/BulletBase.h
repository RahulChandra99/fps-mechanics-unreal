// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBase.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class FPSSYSTEM_API ABulletBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bullet", meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* BulletMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bullet", meta=(AllowPrivateAccess=true))
	USphereComponent* HitSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Bullet", meta=(AllowPrivateAccess=true))
	UProjectileMovementComponent* ProjectileMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnImpact(UPrimitiveComponent* ImpactComponent, AActor* OtherActor, UPrimitiveComponent* Othercomp, FVector NormalImpulse, const FHitResult& Hit);

};
