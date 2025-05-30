// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GSoundManager.generated.h"

UCLASS()
class MYPROJECT_API AGSoundManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGSoundManager();

	UFUNCTION(BlueprintCallable, Category = "CSVWriter")
	void SetCsvFileName(FString fileNameChosen);

	UFUNCTION(BlueprintCallable, Category = "CSVWriter")
	void AddToCsv(int gabarito, int resposta);

	//UFUNCTION(BlueprintCallable, Category = "CSVWriter")
	void WriteToCsv();

private:
	TArray<int> tPosition{};
	TArray<int> aPosition{};
	FString fileName;
};

UCLASS()
class YOURPROJECT_API AGSoundManager : public AActor
{
	GENERATED_BODY()

public:
	AGSoundManager();

	UFUNCTION(BlueprintCallable, Category = "File")
	void SaveArrayToFile(const TArray<FVector>& Positions, const FString& Filename);
};
