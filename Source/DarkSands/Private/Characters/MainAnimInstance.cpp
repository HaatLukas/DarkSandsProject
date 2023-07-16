// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainAnimInstance.h"
#include "DarkSands/Characters/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());

	if (MainCharacter)
	{
		MainMovementComponent = MainCharacter->GetCharacterMovement();
	}
}

void UMainAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (MainMovementComponent)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(MainMovementComponent->Velocity);
		CharacterState = MainCharacter->GetCharacterState();
		IsFalling = MainMovementComponent->IsFalling();
	}
}