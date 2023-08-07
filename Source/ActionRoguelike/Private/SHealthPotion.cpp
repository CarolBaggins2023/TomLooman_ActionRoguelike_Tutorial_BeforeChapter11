// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthPotion.h"

#include "SAttributeComponent.h"

// Sets default values
ASHealthPotion::ASHealthPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	HealingAmount = 50.0f;

	ReactivationDelay = 5.0f;
}

void ASHealthPotion::Reactivate() {
	MeshComp->SetVisibility(true);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void ASHealthPotion::Interact_Implementation(APawn* InstigatorPawn) {
	if (IsValid(InstigatorPawn) && MeshComp->IsVisible()) {
		USAttributeComponent *AttributeComp = Cast<USAttributeComponent>(
			InstigatorPawn->GetComponentByClass(USAttributeComponent::StaticClass())
			);
		if (IsValid(AttributeComp) && AttributeComp->IsInjured()) {
			AttributeComp->ApplyHealthChange(HealingAmount);

			MeshComp->SetVisibility(false);
			MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			GetWorldTimerManager().SetTimer(TimerHandle_Activation, this,
				&ASHealthPotion::Reactivate, ReactivationDelay);
		}
	}
}

// Called when the game starts or when spawned
void ASHealthPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASHealthPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

