#include "TestGameInstance.h"

#include <iostream>

#include "Spark/Core/Screen.h"

void TestGameInstance::BeginPlay()
{
	GetScreen()->Quit();
}

void TestGameInstance::EndPlay()
{
	std::cout << "End play!\n";
}
