// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

class USoundBase;
class UBoxComponent;

/**
 * 
 */
UCLASS()
class DARKSANDS_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	TArray<AActor*> ActorsIgnore;
	AWeapon();
	void DeactivateEmberParticles();
	void Equip(USceneComponent* InParent, const FName& Name, AActor* NewOwner,APawn* NewInstigator);
	void DisableSphereCollision();
	void PlayEquipSound();
	void AttachMeshToSocket(USceneComponent* InParent, const FName& Name);

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	bool ActorsAreBothEnemy(AActor* OtherActor);
	void ExecuteGetHit(FHitResult& BoxHit);
	UFUNCTION(BlueprintImplementableEvent)
	void CreateField(const FVector& FieldLocation);
private:
	void BoxTrace(FHitResult& BoxHit);

	UPROPERTY(EditAnywhere, Category="Weapon Properties")
	FVector BoxTraceExtent = FVector(5.f);

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
		bool bShowDebugBox = false;

	UPROPERTY(EditAnywhere, Category="Weapon")
	USoundBase* EquipSound;
	UPROPERTY(EditAnywhere, Category = "Weapon")
	UBoxComponent* WeaponBox;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float Damage = 20.f;
	
public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }
};
