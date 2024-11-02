// Fill out your copyright notice in the Description page of Project Settings.


#include "MotionDetector.h"

#include "GameFramework/Character.h"

// Sets default values for this component's properties
UMotionDetector::UMotionDetector()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMotionDetector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Character         = Cast<ACharacter>(GetOwner());
	CharacterMovement = Character->GetCharacterMovement();
}


// Called every frame
void UMotionDetector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UMotionDetector::IsMoving()
{
	if (CharacterMovement == nullptr) return false;
	return CharacterMovement->Velocity.Length() > MinWalkSpeed
		&& CharacterMovement->GetCurrentAcceleration() != FVector::ZeroVector;
}
