// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "GameComponents/AttributesComponent.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "BaseCharacter.generated.h"


class AWeapon;
class UAttributesComponent;
class UAnimMontage;

UCLASS()
class DARKSANDS_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual void Tick(float DeltaTime) override;
	

protected:
	virtual void BeginPlay() override;
	
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName);
	int32 PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames);
	/* Montage*/
	virtual int32 PlayAttackMontage();
	virtual int32 PlayDeathMontage();
	void PlayHitMontage(const FName& SectionName);
	void StopAttackMontage();

	

	UFUNCTION(BlueprintCallable)
		FVector GetTranslationWarpTarget();
	UFUNCTION(BlueprintCallable)
		FVector GetRotationWarpTarget();


	virtual void Attack();
	virtual void Die();
	void DirectionalHitReaction(const FVector& ImpactPoint);
	void PlayHitSound(const FVector& ImpactPoint);
	void SpawnHitParticles(const FVector& ImpactPoint);
	virtual void HandleDamage(float DamageAmount);
	virtual bool CanAttack();
	virtual bool IsAlive();

	void DisableCapsuleComponentCollision();

	UFUNCTION(BlueprintCallable)
	virtual void AttackEnd();

	UFUNCTION(BlueprintCallable)
		void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
		AWeapon* EquippedWeapon;

	/*
	* Components	
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UAttributesComponent* Attributes;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
		AActor* CombatTarget;

	UPROPERTY(EditAnywhere, Category = "Combat")
		double WartTargetDistance = 75.f;
	

private:



	UPROPERTY(EditAnywhere, Category = "Sounds")
		USoundBase* HitSound;
	UPROPERTY(EditAnywhere, Category = "Visual Effects")
		UParticleSystem* HitParticles;
	/*
	* Animation Montages
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* AttackMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* HitReactMontage;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere, Category = "Combat")
		TArray<FName> AttackMontageSections;

	UPROPERTY(EditAnywhere, Category = "Combat")
		TArray<FName> DeathMontageSections;


};
