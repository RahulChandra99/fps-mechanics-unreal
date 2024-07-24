// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RCCharacterBase.h"

#include "Camera/CameraComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapons/WeaponBase.h"

// Sets default values
ARCCharacterBase::ARCCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(GetRootComponent());

	MeshFP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh FP"));
	MeshFP->SetupAttachment(CameraComponent);
	
}

// Called when the game starts or when spawned
void ARCCharacterBase::BeginPlay()
{
	Super::BeginPlay();



	//only player can see arms 
	MeshFP->SetOwnerNoSee(false);
	MeshFP->SetOnlyOwnerSee(true);
	MeshFP->SetCastShadow(false);
	MeshFP->SetReceivesDecals(false);

	//default mesh
	GetMesh()->SetOnlyOwnerSee(false);
	GetMesh()->SetOwnerNoSee(true);

	CameraComponent->bUsePawnControlRotation = true;

	DefaultWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

}

// Called every frame
void ARCCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARCCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &ARCCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &ARCCharacterBase::MoveRight);
	/*PlayerInputComponent->BindAxis(TEXT("Move Up"), this, &ARCCharacterBase::MoveForward;*/
	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &ARCCharacterBase::Turn);
	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Gamepad"), this, &ARCCharacterBase::TurnRate);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &ARCCharacterBase::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Gamepad"), this, &ARCCharacterBase::LookUpRate);
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed, this, &ARCCharacterBase::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Released, this, &ARCCharacterBase::StopJump);
	PlayerInputComponent->BindAction(TEXT("Sprint"),IE_Pressed, this, &ARCCharacterBase::StartSprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"),IE_Released, this, &ARCCharacterBase::StopSprint);
	PlayerInputComponent->BindAction(TEXT("Shoot"),IE_Pressed, this, &ARCCharacterBase::StartShoot);
	PlayerInputComponent->BindAction(TEXT("Shoot"),IE_Released, this, &ARCCharacterBase::StopShoot);

}

void ARCCharacterBase::MoveForward(float Value)
{
	if(Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
	else
	{
		StopSprint();
	}
}

void ARCCharacterBase::MoveRight(float Value)
{
	if(Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ARCCharacterBase::MoveUp(float Value)
{
	if(Value != 0.0f)
	{
		AddMovementInput(GetActorUpVector(), Value);
	}
}

void ARCCharacterBase::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ARCCharacterBase::TurnRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ARCCharacterBase::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ARCCharacterBase::LookUpRate(float Value)
{
	AddControllerPitchInput(Value * BaseLookAtRate * GetWorld()->GetDeltaSeconds());
}

void ARCCharacterBase::StartJump()
{
	Jump();
}

void ARCCharacterBase::StopJump()
{
	StopJumping();
}

void ARCCharacterBase::StartShoot()
{
	if(EquippedWeapon)
	{
		EquippedWeapon->StartFiring();
	}
}

void ARCCharacterBase::StopShoot()
{
	if(EquippedWeapon)
	{
		EquippedWeapon->StopFiring();
	}
}

void ARCCharacterBase::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxSprintSpeed;
}

void ARCCharacterBase::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultWalkSpeed;
}

AWeaponBase* ARCCharacterBase::GetEquippedWeapon()
{
	return EquippedWeapon;
}

AWeaponBase* ARCCharacterBase::EquipWeapon(TSubclassOf<AWeaponBase> NewWeapon)
{
	if(EquippedWeapon)
	{
		UnEquipWeapon();
	}

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	EquippedWeapon = GetWorld()->SpawnActor<AWeaponBase>(NewWeapon, Params);

	/*EquippedWeapon->AttachToComponent(MeshFP, FAttachmentTransformRules::SnapToTargetIncludingScale,AttachSocket);*/
	 // Set custom transform
        if (EquippedWeapon)
        {
            // Define your custom transform here
            EquippedWeapon->GetCustomTransform().SetLocation(FVector(0.0f, 0.0f, 0.0f)); // Replace with your custom location
            EquippedWeapon->GetCustomTransform().SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f))); // Replace with your custom rotation
            EquippedWeapon->GetCustomTransform().SetScale3D(FVector(1.0f, 1.0f, 1.0f)); // Replace with your custom scale
    
            // Set the weapon's transform
            EquippedWeapon->SetActorTransform(EquippedWeapon->GetCustomTransform());
            
            // Attach the weapon to the character
            EquippedWeapon->AttachToComponent(MeshFP, FAttachmentTransformRules::KeepRelativeTransform, AttachSocket);
        }

	return EquippedWeapon;
}

void ARCCharacterBase::UnEquipWeapon()
{
	if(EquippedWeapon)
	{
		EquippedWeapon->OnUnEquipped();
		EquippedWeapon->Destroy();
	}
}

