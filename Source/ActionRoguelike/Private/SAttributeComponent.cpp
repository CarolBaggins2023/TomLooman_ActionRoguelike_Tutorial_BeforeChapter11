// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values
USAttributeComponent::USAttributeComponent()
{
	Health = 100.0f;

	HealthMax = 100.0f;
}

bool USAttributeComponent::ApplyHealthChange(float Delta) {
	Health = FMath::Clamp(Health + Delta, 0, HealthMax);

	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);
	
	return true;
}

bool USAttributeComponent::IsAlive() {
	return Health > 0.0f;
}

bool USAttributeComponent::IsInjured() {
	return Health < HealthMax;
}

