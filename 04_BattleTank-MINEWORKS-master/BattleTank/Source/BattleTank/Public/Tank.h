// Copyright EmbraceIT Ltd.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

		ATank();
public:
	virtual float TakeDamage(float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser) override;

	FTankDelegate OnDeath;


private:
UPROPERTY(EditDefaultsOnly, Category = "Setup")
int32 StartingHealth = 100;

UPROPERTY(VisibleAnywhere, Category = "Health")
int32 CurrentHealth = StartingHealth;
};

