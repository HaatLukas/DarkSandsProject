// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Interfaces/HitInterface.h"
#include "DarkSands/Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UHealthBarComponent;
class UPawnSensingComponent;

UCLASS()
class DARKSANDS_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemy();

	/* <AActor> */
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Destroyed() override;
	/* </AActor> */

	/* <IHitInterface> */
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	/* </IHitInterface> */

protected:
	/* <AActor> */
	virtual void BeginPlay() override;
	/* </AActor> */

	/* <ABaseCharacter> */
	virtual void Die() override;
	virtual void Attack() override;
	virtual bool CanAttack() override;
	virtual void HandleDamage(float DamageAmount) override;
	virtual void AttackEnd() override;
	virtual int32 PlayDeathMontage() override;
	/* </ABaseCharacter> */
	bool InTargetRange(AActor* Target, double AcceptanceRadius);
	void MoveToTarget(AActor* Target);
	AActor* ChoosePatrolTarget();
	
	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<EDeathPose> DeathPose;

	UPROPERTY(BlueprintReadOnly)
		EEnemyState EnemyState = EEnemyState::EES_Patrolling;

	UPROPERTY(EditAnywhere)
		double CombatRadius = 650.f;

	UPROPERTY(EditAnywhere)
		double AttackRadius = 165.f;

	UPROPERTY(BlueprintReadOnly, Category="Combat")
		AActor* CombatTarget;

	UPROPERTY( EditAnywhere, Category = "Combat")
		float AttackMin = 0.5f;
	UPROPERTY( EditAnywhere, Category = "Combat")
		float AttackMax = 1.f;

	UPROPERTY( EditAnywhere, Category = "Combat")
		float ChasingSpeed = 300.f;

	UPROPERTY( EditAnywhere, Category = "Combat")
		float PatrolSpeed = 125.f;

private:
	/* AI Behavior */
	void CheckPatrolTarget();
	void CheckCombatTarget();
	void PatrolTimerFinished();
	void ClearPatrolTimer();
	void HideHealthBar();
	void ShowHealthBar();
	void LoseInterest();
	void StartPatrolling();
	void ChaseTarget();
	bool IsOutsideCombatRadius();
	bool IsOutsideAttackRadius();
	bool IsInsideAttackRadius();
	bool IsChasing();
	bool IsAttacking();
	bool IsDead();
	bool IsEngaged();

	void SpawnDefaultWeapon();
	void InitializeEnemy();

	UFUNCTION()
		void PawnSeen(APawn* SeenPawn);
	

	UPROPERTY()
		class AAIController* EnemyController;
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
		AActor* CurrentPatrolTarget;
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
		TArray<AActor*>PatrolTargets;
	UPROPERTY(EditAnywhere)
		double PatrolRadius = 200.f;

	UPROPERTY(VisibleAnywhere)
		UPawnSensingComponent* PawnSensingComponent;

	UPROPERTY(VisibleAnywhere)
		UHealthBarComponent* HealthBarWidget;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWeapon>WeaponClass;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
		float WaitMin = 5.f;
	UPROPERTY(EditAnywhere, Category = "AI Navigation")
		float WaitMax = 10.f;


	/* Combat */

	
	void StartAttackTimer();
	void ClearAttackTimer();

	FTimerHandle AttackTimer;
	FTimerHandle PatrolTimer;

	

	

	UPROPERTY(EditAnywhere, Category = "Combat")
		float LifeSpanAfterDeath = 5.f;
	


};
