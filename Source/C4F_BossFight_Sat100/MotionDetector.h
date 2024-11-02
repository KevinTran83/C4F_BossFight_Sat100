// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "MotionDetector.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class C4F_BOSSFIGHT_SAT100_API UMotionDetector : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMotionDetector();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY ( EditAnywhere, BlueprintReadWrite, Category="BossFighter",
		        meta=(AllowPrivateAccess="true")
	          ) float MinWalkSpeed = 3.0f;
	ACharacter *Character;
	UCharacterMovementComponent *CharacterMovement;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable) bool IsMoving();
};
