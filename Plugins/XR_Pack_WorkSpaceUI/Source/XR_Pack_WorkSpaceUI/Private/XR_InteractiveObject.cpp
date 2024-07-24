#include "XR_InteractiveObject.h"
#include "W_InteractiveOptions.h"

AXR_InteractiveObject::AXR_InteractiveObject()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootComponent);
	InteractiveComponent = CreateDefaultSubobject<UXR_InteractiveComponent>("InteractiveComponent");
	InteractiveComponent->SetupAttachment(StaticMesh);
}

void AXR_InteractiveObject::BeginPlay()
{
	Super::BeginPlay();

	InteractiveComponent->BindFunctionToButton(this, "DoSomething_1");
	InteractiveComponent->BindFunctionToButton(this, "DoSomething_2");
	InteractiveComponent->BindFunctionToButton(this, "DoSomething_3", true);
}

void AXR_InteractiveObject::DoSomething_1()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("DoSomething_1"));
}

void AXR_InteractiveObject::DoSomething_2()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("DoSomething_2"));
}

void AXR_InteractiveObject::DoSomething_3()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("DoSomething_3"));
}

void AXR_InteractiveObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

