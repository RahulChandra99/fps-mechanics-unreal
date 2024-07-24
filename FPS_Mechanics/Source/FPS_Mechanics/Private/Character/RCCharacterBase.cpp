// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RCCharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ARCCharacterBase::ARCCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(GetRootComponent());

	MeshFP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh FP"));
	MeshFP->SetupAttachment(CameraComponent);

	
	//only player can see arms 
	MeshFP->SetOwnerNoSee(false);
	MeshFP->SetOnlyOwnerSee(true);
	MeshFP->SetCastShadow(false);
	MeshFP->SetReceivesDecals(false);

	//default mesh
	GetMesh()->SetOnlyOwnerSee(false);
	GetMesh()->SetOwnerNoSee(true);
}



// Called when the game starts or when spawned
void ARCCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
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

}

