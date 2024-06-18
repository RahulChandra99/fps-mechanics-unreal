// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RCCharacterBase.generated.h"

class UCameraComponent;

UCLASS()
class FPS_MECHANICS_API ARCCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Character", meta = (AllowPrivateAccess="true"))
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Character", meta = (AllowPrivateAccess="true"))
	USkeletalMeshComponent* Mesh1P;

public:
	// Sets default values for this character's properties
	ARCCharacterBase();

	UCameraComponent* GetCameraComponent() { return CameraComp; }
	USkeletalMeshComponent* GetMesh1P () { return Mesh1P; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS")
	float BaseTurnRate = 45.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS")
	float BaseLookRate = 45.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPS")
	float MaxSprintSpeed = 900.0;

	void MoveRight(float Value);
	void MoveForward(float Value);
	void MoveUp(float Value);

	void Turn(float Value);
	void TurnRate(float Value);
	void LookUp(float Value);
	void LookUpRate(float Value);
	void StartJump();
	void StopJump();

	void StartSprint();
	void StopSprint();
	
private:
	float DefaultWalkSpeed;
	
	

};
