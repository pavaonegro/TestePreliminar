#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_InteractiveButton.h"
#include <Components/Overlay.h>
#include "W_InteractiveOptions.generated.h"

UCLASS()
class XR_PACK_WORKSPACEUI_API UW_InteractiveOptions : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION()
	UW_InteractiveButton* CreateInteractiveButton(FText FunctionName);
	UFUNCTION()
	void ChangeDisplayOption();
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UW_InteractiveButton> ButtonClass;

protected:

	virtual void NativeConstruct() override;

	UFUNCTION()
	void GoToNextOption();
	UFUNCTION()
	void GoToPreviousOption();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UW_InteractiveButton* Left_Arrow;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UW_InteractiveButton* Right_Arrow;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UOverlay* Overlay;

private:
	int curOption = 0;
	TArray<UW_InteractiveButton*> Buttons;
};
