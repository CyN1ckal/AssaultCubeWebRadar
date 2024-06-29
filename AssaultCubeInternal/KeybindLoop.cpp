#include "pch.h"

extern bool CheatAlive;

extern Config config;

void KeybindLoop()
{

	std::cout << "Starting Keybind Loop\n";

	while (CheatAlive)
	{

		if (GetAsyncKeyState(VK_HOME) & 1)
		{
			config.bRefreshHealth = !config.bRefreshHealth;
			printf("Toggled Refresh Health: %d\n", config.bRefreshHealth);
		}

		if (GetAsyncKeyState(VK_PRIOR) & 1)
		{
			config.bPrintPlayerCoords = !config.bPrintPlayerCoords;
			printf("Toggled Print Player Coords: %d\n", config.bPrintPlayerCoords);
		}

		if (GetAsyncKeyState(VK_CONTROL) & 1)
		{
			TestPostRequest();
		}

	}

}