// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RCCharacterBase.generated.h"

class UCameraComponent;

UCLASS()
class FPSSYSTEM_API ARCCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="RC Character",meta=(AllowPrivateAccess = true))
	UCameraComponent* CameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category="RC Character",meta=(AllowPrivateAccess = true))
	USkeletalMeshComponent* MeshFP;

public:
	// Sets default values for this character's properties
	ARCCharacterBase();

	UCameraComponent* GetCameraComponenet() { return CameraComponent;}

	USkeletalMeshComponent* GetMeshFP(){return MeshFP;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RC Character")
	float BaseTurnRate = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RC Character")
	float BaseLookAtRate = 45.0f;

	float MaxSprintSpeed = 10000.0f;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUp(float Value);
	void Turn(float Value);
	void TurnRate(float Value);
	void LookUp(float Value);
	void LookUpRate(float Value);
	
	void StartJump();
	void StopJump();
	void StartShoot();
	void StopShoot();
	void StartSprint();
	void StopSprint();

private:
	float DefaultWalkSpeed;


};
