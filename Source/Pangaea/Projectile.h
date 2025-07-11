// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.generated.h"

UCLASS(Blueprintable)
class AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	UPROPERTY(EditAnywhere, Category = "Projectile Prarms")
	float Speed = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Projectile Prarms")
	float Lifespan = 5.0f;
	UPROPERTY(EditAnywhere, Category = "Projectile Prarms")
	float Damage = 10.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float _LifeCountingDown;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
