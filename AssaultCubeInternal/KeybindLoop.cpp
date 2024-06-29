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

		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			config.bSendRadarData = !config.bSendRadarData;
			printf("Toggled Radar Data: %d\n", config.bSendRadarData);
		}

	}

}