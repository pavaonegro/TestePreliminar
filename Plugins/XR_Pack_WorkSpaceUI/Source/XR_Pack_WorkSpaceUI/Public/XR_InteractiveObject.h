#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <XR_InteractiveComponent.h>
#include "XR_InteractiveObject.generated.h"

UCLASS()
class XR_PACK_WORKSPACEUI_API AXR_InteractiveObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AXR_InteractiveObject();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UXR_InteractiveComponent* InteractiveComponent;

	//Functions-Test
	UFUNCTION()
	void DoSomething_1();
	UFUNCTION()
	void DoSomething_2();
	UFUNCTION()
	void DoSomething_3();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
