// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HealthComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	StartingHealth = StartingHealth == 0 ? MaxHealth : StartingHealth;
	CurrentHealth = StartingHealth;

	if(GetOwner())
	{
		GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OwnerTakeDamage);
	}
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

bool UHealthComponent::GetIsDead()
{
	return CurrentHealth <= 0.0;
}

void UHealthComponent::OwnerTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth = CurrentHealth - Damage;
	CurrentHealth = FMath::Clamp<float>(CurrentHealth,0.0,MaxHealth);

	OnHealthChanged.Broadcast(CurrentHealth);

	if(GetIsDead())
	{
		OnDied.Broadcast();
	}
}