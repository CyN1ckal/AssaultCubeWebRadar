#include "pch.h"

extern bool CheatAlive;

extern Config config;

void MainLoop()
{

	std::cout << "Starting Main Loop\n";

	while (CheatAlive)
	{
		if (GetAsyncKeyState(VK_END) & 1)
		{
			CheatAlive = false;
			break;
		}

		if (config.bRefreshHealth)
		{
			RefreshHealth();
		}

		if (config.bPrintPlayerCoords)
		{
			PrintPlayerCoords();
		}

		if (config.bSendRadarData)
		{
			PrintPlayerlistAndSendJSON();
			//http::Request request{ "http://localhost:4000/set" };
			//std::string body = "{\"playerlist\":{\"123\":\"456\"}}";
			//const auto response = request.send("POST", body, {
			//	{"Content-Type", "application/json"}
			//	}, std::chrono::milliseconds(500));
		}

		if (GetAsyncKeyState(VK_DELETE) & 1)
		{
		}

	}

}
