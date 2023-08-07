// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SHealthPotion.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASHealthPotion : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASHealthPotion();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *MeshComp;

	UPROPERTY(EditAnywhere)
	float HealingAmount;

	FTimerHandle TimerHandle_Activation;

	UPROPERTY(EditAnywhere)
	float ReactivationDelay;

	UFUNCTION(BlueprintCallable)
	void Reactivate();
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
