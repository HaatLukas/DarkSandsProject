// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SandOverlay.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class DARKSANDS_API USandOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetHealthBarPercent(float Percent);
	void SetStaminaBarPercent(float Percent);
	void SetGold(int32 Gold);
	void SetSouls(int32 Souls);

private:
	UPROPERTY(meta = (BindWidget))
		 UProgressBar* HealthBarProgressBar;
	UPROPERTY(meta = (BindWidget))
		UProgressBar* StaminaProgressBar;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* SoulsCountText;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* GoldCountText;


	
};
