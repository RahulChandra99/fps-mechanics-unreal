// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HealthComp.h"
#include "GameFramework/Actor.h"

void UHealthComp::OnOwnerTakenDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth = CurrentHealth - Damage;
	FMath::Clamp<float>(CurrentHealth, 0.0, MaxHealth);

	OnHealthChanged.Broadcast(CurrentHealth);

	if (GetIsDead())
	{
		OnDied.Broadcast();
	}
}

// Sets default values for this component's properties
UHealthComp::UHealthComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


float UHealthComp::GetCurrentHealth()
{
	return CurrentHealth;
}

bool UHealthComp::GetIsDead()
{
	return CurrentHealth <= 0.0;
}

// Called when the game starts
void UHealthComp::BeginPlay()
{
	Super::BeginPlay();

	Super::BeginPlay();

	StartingHealth = StartingHealth == 0 ? MaxHealth : StartingHealth;
	CurrentHealth = StartingHealth;

	//Checking if pointer points to something by using if statement
	if (GetOwner())
	{
		GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComp::OnOwnerTakenDamage);
	}

	
}


// Called every frame
void UHealthComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

