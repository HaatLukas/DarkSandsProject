// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DARKSANDS_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributesComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float CurrentHealth;
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float MaxHealth;
	
public:
	FORCEINLINE void ReceiveDamage(const float& Damage);
	float GetHealthPercent();
	FORCEINLINE bool IsAlive();
};
