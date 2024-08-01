// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BulletBase.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABulletBase::ABulletBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Hit Sphere"));
	SetRootComponent(HitSphere);
	HitSphere->InitSphereRadius(12.0);
	HitSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	HitSphere->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	HitSphere->SetNotifyRigidBodyCollision(true);
	
	BulletMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet Mesh"));
	BulletMeshComp->SetupAttachment(HitSphere);
	BulletMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if(GetOwner())
	{
		BulletMeshComp->IgnoreActorWhenMoving(GetOwner(), true);
	}
	if(GetOwner() && GetOwner()->GetOwner())
	{
		BulletMeshComp->IgnoreActorWhenMoving(GetOwner()->GetOwner(), true);
	}
	
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->InitialSpeed = 3000.0;
	ProjectileMovementComponent->Velocity = FVector(1.0,0.0,0.0);
	

}

// Called when the game starts or when spawned
void ABulletBase::BeginPlay()
{
	Super::BeginPlay();

	HitSphere->OnComponentHit.AddDynamic(this, ABulletBase::OnImpact);
	
}

// Called every frame
void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletBase::OnImpact(UPrimitiveComponent* ImpactComponent, AActor* OtherActor, UPrimitiveComponent* Othercomp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor)
	{
		OtherActor->TakeDamage()
	}
}

