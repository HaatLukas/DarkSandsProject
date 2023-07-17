// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SandOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USandOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthBarProgressBar)
		HealthBarProgressBar->SetPercent(Percent);
}

void USandOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar)
		StaminaProgressBar->SetPercent(Percent);
}

void USandOverlay::SetGold(int32 Gold)
{
	if (GoldCountText)
		GoldCountText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Gold)));
}

void USandOverlay::SetSouls(int32 Souls)
{
	if(SoulsCountText)
		SoulsCountText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Souls)));

}

