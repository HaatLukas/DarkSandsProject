// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DarkSands/DebugMacros.h"
#include "Item.generated.h"

class USphereComponent;

enum class EItemState :uint8
{
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class DARKSANDS_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(VisibleAnywhere)
		USphereComponent* Sphere;

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sin Parameters")
		float Amplitude = 0.25f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sin Parameters")
		float TimeConstant = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* ItemMesh;

	UFUNCTION(BlueprintPure)
		float TransformedSin();

	UFUNCTION(BlueprintPure)
		float TransformedCos();

	UFUNCTION(BlueprintCallable)
		void Rotate(float RotationValue);

	template<typename T>
	T avg(T first, T second);

	
	UFUNCTION()
		virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	EItemState ItemState = EItemState::EIS_Hovering;

	UPROPERTY(EditAnywhere, Category="Niagara")
	class UNiagaraComponent* EmberParticles;

	
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float RunningTime;


};


template<typename T>
inline T AItem::avg(T First, T Second)
{
	return (First + Second) / 2;
}