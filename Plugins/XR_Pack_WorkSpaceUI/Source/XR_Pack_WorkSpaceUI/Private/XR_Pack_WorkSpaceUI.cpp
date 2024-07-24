// Copyright Epic Games, Inc. All Rights Reserved.

#include "XR_Pack_WorkSpaceUI.h"

#define LOCTEXT_NAMESPACE "FXR_Pack_WorkSpaceUIModule"

void FXR_Pack_WorkSpaceUIModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FXR_Pack_WorkSpaceUIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXR_Pack_WorkSpaceUIModule, XR_Pack_WorkSpaceUI)