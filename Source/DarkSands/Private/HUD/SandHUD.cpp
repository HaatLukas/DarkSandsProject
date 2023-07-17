



// Fill out your copyright notice in the Description page of P


#include "HUD/SandHUD.h"
#include "HUD/SandOverlay.h"

void ASandHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller && SandOverlayClass)
		{
			CreateWidget<USandOverlay>(Controller, SandOverlayClass);
			SandOverlay->AddToViewport();
		}
	}
}
