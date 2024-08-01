// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/WeaponBase.h"

#include "Components/ArrowComponent.h"
#include "Weapons/BulletBase.h"

// Sets default values
AWeaponBase::AWeaponBase()
	:BulletClass(ABulletBase::StaticClass())
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootComp);
	
	MuzzlePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Muzzle"));
	MuzzlePoint->ArrowSize = 0.25f;
	MuzzlePoint->ArrowColor = FColor::Yellow;
	MuzzlePoint->SetupAttachment(RootComp);
	
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FTransform AWeaponBase::GetCustomTransform()
{
	return CustomTransform;
}

void AWeaponBase::FireRound()
{
	if(RemainingAmmo > 0.0)
	{
		RemainingAmmo--;
		AActor* BulletOwner = this;
		
		const FTransform SpawnTransform = MuzzlePoint->GetComponentTransform();
		
		FActorSpawnParameters Params;
		Params.Owner = BulletOwner;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		
		GetWorld()->SpawnActor<AActor>(BulletClass, SpawnTransform, Params);

		OnFiredRound();
	}
	
}


void AWeaponBase::StartFiring_Implementation()
{
	if(!BulletClass)
	{
		return;
	}

	if(bFullyAutomatic)
	{
		GetWorldTimerManager().SetTimer(ReFireHandle, this, &AWeaponBase::FireRound, ReFireRate, true);
		FireRound();
	}
	else
	{
		FireRound();
	}
	
	
}

void AWeaponBase::StopFiring_Implementation()
{
	GetWorldTimerManager().ClearTimer(ReFireHandle);
}





