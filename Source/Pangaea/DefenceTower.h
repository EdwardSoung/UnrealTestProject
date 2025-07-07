// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DefenceTower.generated.h"

UCLASS(Blueprintable)
class ADefenceTower : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
		Category = "Tower Component", 
		meta = (AllowPrivateAccess = "true"))
	UBoxComponent* _BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
		Category = "Tower Component",
		meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* _MeshComponent;

public:	
	// Sets default values for this actor's properties
	ADefenceTower();

	UPROPERTY(EditAnywhere, Category = "Tower Prarms")
	int HealthPoints = 500;
	UPROPERTY(EditAnywhere, Category = "Tower Prarms")
	int ShellDefence = 3;
	UPROPERTY(EditAnywhere, Category = "Tower Prarms")
	float AttackRange = 6.0f;
	UPROPERTY(EditAnywhere, Category = "Tower Prarms")
	float REloadInterval = 1.0f;	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int _HealthPoints;
	int _ReloadCountingDown;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, 
		Category = "Pangaea|Defence Tower",
		meta = (DisplayName = "Get HP"))
	int GetHealthPoints();

	UFUNCTION(BlueprintCallable,
		Category = "Pangaea|Defence Tower")
	bool IsDestroyed();
	UFUNCTION(BlueprintCallable,
		Category = "Pangaea|Defence Tower")
	bool CanFire();
	void Fire();
	void Hit(int damage);

	FORCEINLINE UBoxComponent* GetBoxComponent() const
	{
		return _BoxComponent;
	}

	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return _MeshComponent;
	}
	
protected:
	void DestoryProcess();

};
