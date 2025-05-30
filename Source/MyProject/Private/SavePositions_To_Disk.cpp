// SavePositions_To_Disk.cpp
#include "SavePositions_To_Disk.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"


bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting = false)
{

    SaveDirectory += "\\";
    SaveDirectory += FileName;

    if (!AllowOverWriting)
    {
        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
        {
            return false;
        }
    }

    FString FinalString = "";
    for (FString& Each : SaveText)
    {
        FinalString += Each;
        FinalString += LINE_TERMINATOR;
    }

    return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);

}