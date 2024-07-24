#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "W_InteractiveButton.generated.h"

class UButton;

DECLARE_DYNAMIC_DELEGATE(FOnInteraction);

UCLASS()
class XR_PACK_WORKSPACEUI_API UW_InteractiveButton : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FOnInteraction OnInteraction;

	void SetupInteractiveButton(FText Text);
	void SetupInteractiveButton();

protected:

	UFUNCTION(BlueprintCallable)
	void OnButtonClicked();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* Button;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextBlock;
};
