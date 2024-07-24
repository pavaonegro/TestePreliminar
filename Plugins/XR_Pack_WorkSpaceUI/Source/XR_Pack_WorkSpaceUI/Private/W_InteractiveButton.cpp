#include "W_InteractiveButton.h"
#include "Components/Button.h"

void UW_InteractiveButton::SetupInteractiveButton(FText Text)
{
	TextBlock->SetText(Text);
	if (Button)
		Button->OnClicked.AddDynamic(this, &UW_InteractiveButton::OnButtonClicked);
}

void UW_InteractiveButton::SetupInteractiveButton()
{
	if (Button)
		Button->OnClicked.AddDynamic(this, &UW_InteractiveButton::OnButtonClicked);
}

void UW_InteractiveButton::OnButtonClicked()
{
	OnInteraction.Execute();
}
