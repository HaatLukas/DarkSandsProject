// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SandHUD.generated.h"

/**
 * 
 */
UCLASS()
class DARKSANDS_API ASandHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "SandHUD")
		TSubclassOf<class USandOverlay> SandOverlayClass;

	UPROPERTY()
		USandOverlay* SandOverlay;
public:
	FORCEINLINE USandOverlay* GetSandOverlay() const {return SandOverlay;}
};
