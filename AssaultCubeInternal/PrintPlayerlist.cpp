#include "pch.h"

extern Config config;

void SendPlayerData() {

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
			.append("\",\"teamID\":\"")
			.append(std::to_string(ent->TeamID))
			.append("\"}");

		if (i != (PlayerCount - 1)) AllEntInformationString.append(",");

	}

	AllEntInformationString.append("}}");

	//std::cout << AllEntInformationString << std::endl;

	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:4000/set");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, AllEntInformationString);
		res = curl_easy_perform(curl);
		printf("\n");
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

	}
	curl_easy_cleanup(curl);
}