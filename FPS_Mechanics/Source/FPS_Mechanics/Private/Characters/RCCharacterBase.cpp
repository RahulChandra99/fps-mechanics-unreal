// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RCCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARCCharacterBase::ARCCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Template Function
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(GetRootComponent());
	CameraComp->bUsePawnControlRotation = true;
	
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh1P"));
	Mesh1P->SetupAttachment(CameraComp);
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetOwnerNoSee(false);
	Mesh1P->SetCastShadow(false);
	Mesh1P->SetReceivesDecals(false);

	GetMesh() -> SetOnlyOwnerSee(false);
	GetMesh() -> SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void ARCCharacterBase::BeginPlay()
{
	Super::BeginPlay();

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

	PlayerInputComponent->BindAxis(TEXT("MoveForwards"), this, &ARCCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ARCCharacterBase::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &ARCCharacterBase::MoveUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ARCCharacterBase::Turn);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &ARCCharacterBase::TurnRate);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ARCCharacterBase::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &ARCCharacterBase::LookUpRate);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ARCCharacterBase::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ARCCharacterBase::StopJump);

	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &ARCCharacterBase::StartSprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &ARCCharacterBase::StopSprint);
}

void ARCCharacterBase::MoveRight(float Value)
{
	if(Value != 0.0)
	{
		AddMovementInput(GetActorRightVector(),Value);
	}
	else
	{
		StopSprint();
	}
}

void ARCCharacterBase::MoveForward(float Value)
{
	if(Value != 0.0)
	{
		AddMovementInput(GetActorForwardVector(),Value);
	}
}


void ARCCharacterBase::MoveUp(float Value)
{
	if(Value != 0.0)
	{
		AddMovementInput(GetActorUpVector(),Value);
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
	AddControllerPitchInput(Value * BaseLookRate * GetWorld()->GetDeltaSeconds());
}

void ARCCharacterBase::StartJump()
{
	Jump();
}

void ARCCharacterBase::StopJump()
{
	StopJumping();
}

void ARCCharacterBase::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = MaxSprintSpeed;
}

void ARCCharacterBase::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultWalkSpeed;
}

