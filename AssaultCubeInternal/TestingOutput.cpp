#include "pch.h"

extern Config config;

void TestingOutput()
{
	uintptr_t EntityListBase = *(uintptr_t*)(config.ac_clientBaseAddress + Offsets::EntityListOffset);

	// Getting the number of players
	int PlayerCount = *(int*)(config.ac_clientBaseAddress + Offsets::PlayerCountOffset);

	std::string AllEntInformationString = "{\"playerlist\":{";

	// Preparing LocalPlayer data as Player 0
	LocalPlayer* PlayerBaseAddress = (LocalPlayer*)*(uintptr_t*)(config.ac_clientBaseAddress + Offsets::LocalPlayerOffset);

	AllEntInformationString
		.append("\"PlayerNumber0\":{\"x\":\"")
		.append(std::to_string(PlayerBaseAddress->Position.x))
		.append("\",\"y\":\"")
		.append(std::to_string(PlayerBaseAddress->Position.y))
		.append("\",\"yaw\":\"")
		.append(std::to_string(PlayerBaseAddress->ViewAngles.x))
		.append("\",\"pitch\":\"")
		.append(std::to_string(PlayerBaseAddress->ViewAngles.y))
		.append("\",\"teamID\":\"")
		.append(std::to_string(PlayerBaseAddress->TeamID))
		.append("\"},");

	// Looping through entity list and preparing JSON
	for (int i = 1; i < PlayerCount; i++)
	{
		uintptr_t NextEntAddress = EntityListBase + (0x4 * i);

		LocalPlayer* ent = (LocalPlayer*)*(uintptr_t*)NextEntAddress;

		AllEntInformationString
			.append("\"PlayerNumber")
			.append(std::to_string(i))
			.append("\":{\"x\":\"")
			.append(std::to_string(ent->Position.x))
			.append("\",\"y\":\"")
			.append(std::to_string(ent->Position.y))
			.append("\",\"yaw\":\"")
			.append(std::to_string(ent->ViewAngles.x))
			.append("\",\"pitch\":\"")
			.append(std::to_string(ent->ViewAngles.y))
			.append("\",\"teamID\":\"")
			.append(std::to_string(ent->TeamID))
			.append("\"}");

		if (i != (PlayerCount - 1)) AllEntInformationString.append(",");

	}

	AllEntInformationString.append("}}");

	std::cout << AllEntInformationString << std::endl;
}