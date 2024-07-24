#include "XR_InteractiveComponent.h"
#include "W_InteractiveOptions.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

UXR_InteractiveComponent::UXR_InteractiveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UXR_InteractiveComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UXR_InteractiveComponent::BindFunctionToButton(UObject* FunctionOwner, FName FunctionName, bool UpdateDisplay)
{
	UW_InteractiveOptions* Options = GetDisplayOption();
	if (Options) {
		UW_InteractiveButton* Button;
		Button = Options->CreateInteractiveButton(FText::FromString(FunctionName.ToString()));
		Button->OnInteraction.BindUFunction(FunctionOwner, FunctionName);
		if (UpdateDisplay)
			Options->ChangeDisplayOption();
	}
	else {
		UW_InteractiveButton* Button = Cast<UW_InteractiveButton>(GetWidget());
		if (Button)
			Button->OnInteraction.BindUFunction(FunctionOwner, FunctionName);		
	}
}

void UXR_InteractiveComponent::BindFunctionToButton(UObject* FunctionOwner, FName FunctionName, FName DisplayName, bool UpdateDisplay)
{
	UW_InteractiveOptions* Options = GetDisplayOption();
	if (Options) {
		UW_InteractiveButton* Button;
		Button = Options->CreateInteractiveButton(FText::FromString(DisplayName.ToString()));
		Button->OnInteraction.BindUFunction(FunctionOwner, FunctionName);
		if (UpdateDisplay)
			Options->ChangeDisplayOption();
	}
}

void UXR_InteractiveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (OrientToPlayer && GetOwner() && UGameplayStatics::GetPlayerPawn(GetWorld(), 0)) 
	{
		FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetTargetLocation(), UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation());
		//Rotation.Roll = GetComponentRotation().Roll;
		//Rotation.Pitch = GetComponentRotation().Pitch;
		SetWorldRotation(Rotation);
	}
}

UW_InteractiveOptions* UXR_InteractiveComponent::GetDisplayOption()
{
	if (GetWidget()) {
		UW_InteractiveOptions* Option = Cast<UW_InteractiveOptions>(GetWidget());
		return Option;
	}
	return nullptr;
}
