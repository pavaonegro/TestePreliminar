#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "XR_InteractiveComponent.generated.h"

class UW_InteractiveOptions;

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class XR_PACK_WORKSPACEUI_API UXR_InteractiveComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:

	UXR_InteractiveComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void BindFunctionToButton(UObject* FunctionOwner, FName FunctionName, bool UpdateDisplay = false);
	void BindFunctionToButton(UObject* FunctionOwner, FName FunctionName, FName DisplayName, bool UpdateDisplay = false);

	UW_InteractiveOptions* GetDisplayOption();

	UPROPERTY(EditAnywhere)
	bool OrientToPlayer = true;
};
