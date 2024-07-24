#include "W_InteractiveOptions.h"
#include <functional>

UW_InteractiveButton* UW_InteractiveOptions::CreateInteractiveButton(FText FunctionName)
{
	UW_InteractiveButton* IButton = Cast<UW_InteractiveButton>(CreateWidget(this, ButtonClass));
	if (IButton) 
	{
		IButton->SetupInteractiveButton(FunctionName);
		Buttons.Add(IButton);

		if (Overlay)
		{
			Overlay->AddChildToOverlay(IButton);
			int32 index = Overlay->GetChildrenCount() - 1;
			if(index != 0)
				Overlay->GetChildAt(index)->SetVisibility(ESlateVisibility::Hidden);
		}

		return IButton;
	}
	return nullptr;
}

void UW_InteractiveOptions::NativeConstruct()
{
	if (Left_Arrow && Right_Arrow) {
		Left_Arrow->OnInteraction.BindUFunction(this, "GoToPreviousOption");
		Left_Arrow->SetupInteractiveButton();
		Right_Arrow->OnInteraction.BindUFunction(this, "GoToNextOption");
		Right_Arrow->SetupInteractiveButton();
	}
}

void UW_InteractiveOptions::GoToNextOption()
{
	Overlay->GetChildAt(curOption)->SetVisibility(ESlateVisibility::Hidden);
	curOption++;
	ChangeDisplayOption();
}

void UW_InteractiveOptions::GoToPreviousOption()
{
	Overlay->GetChildAt(curOption)->SetVisibility(ESlateVisibility::Hidden);
	curOption--;
	ChangeDisplayOption();
}

void UW_InteractiveOptions::ChangeDisplayOption()
{
	//Isso coloca e remove as widgets do Overlay, o que pode estar acontecendo no crash é quando tu remove e tenta colocar outro mas a referência ainda não foi limpa
	//Normalmente isso pode dar algum erro.
	//O que fazer??? Colocar todos os botões no Overlay e só dar setvisibility no que você quer exibir, isso possibilita que as referencias não sejam deletadas!!!!!!
	//Acredito que isso resolva o teu crash
	if (Overlay) {
		curOption = (curOption % Buttons.Num() + Buttons.Num()) % Buttons.Num();
		Overlay->GetChildAt(curOption)->SetVisibility(ESlateVisibility::Visible);
	}
}
