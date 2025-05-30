#pragma once



#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SavePositions_To_Disk.h"


UCLASS()
class MyProject UTextFileManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    UFUNCTION(BlueprintCallable, Category = "Custom", meta = (KeyWords = "Save")
    static bool SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting);


};