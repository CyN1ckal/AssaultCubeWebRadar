#include "pch.h"

extern Config config;

void PrintPlayerlist() {

	uintptr_t EntityListBase = *(uintptr_t*)(config.ac_clientBaseAddress + Offsets::EntityListOffset);
	
	// Getting the number of players
	int PlayerCount = *(int*)(config.ac_clientBaseAddress + Offsets::PlayerCountOffset);

	// Looping through entity list
	for (int i = 1; i < PlayerCount ; i++)
	{
		printf("\n");

		uintptr_t NextEntAddress = EntityListBase + (0x4 * i);

		printf("%X\n", NextEntAddress);

		LocalPlayer* ent = (LocalPlayer*)*(uintptr_t*)NextEntAddress;

		printf("Name,x,y : %s,%f,%f\n", ent->Name,ent->Position.x, ent->Position.y);
	}
}

void PrintPlayerlistAndSendString() {

	uintptr_t EntityListBase = *(uintptr_t*)(config.ac_clientBaseAddress + Offsets::EntityListOffset);

	// Getting the number of players
	int PlayerCount = *(int*)(config.ac_clientBaseAddress + Offsets::PlayerCountOffset);

	std::vector<std::string> jsonStrings = {};

	std::string AllEntInformationString = {};

	// Looping through entity list
	for (int i = 1; i < PlayerCount; i++)
	{
		uintptr_t NextEntAddress = EntityListBase + (0x4 * i);

		LocalPlayer* ent = (LocalPlayer*)*(uintptr_t*)NextEntAddress;

		std::string EntInformationString = {};

		std::string DelimitingString = "**";

		EntInformationString
			.append(ent->Name)
			.append(DelimitingString)
			.append(std::to_string(ent->Position.x))
			.append(DelimitingString)
			.append(std::to_string(ent->Position.y))
			.append(DelimitingString)
			.append(std::to_string(ent->ViewAngles.x))
			.append(DelimitingString)
			.append(std::to_string(ent->ViewAngles.y))
			.append(DelimitingString)
			.append(std::to_string(ent->TeamID))
			;

		AllEntInformationString.append("{");
		AllEntInformationString.append(EntInformationString);
		AllEntInformationString.append("}");
		AllEntInformationString.append(",");

		//std::cout << EntInformationString << std::endl;
		//printf("Name,x,y : %s,%f,%f\n", ent->Name, ent->Position.x, ent->Position.y);
	
		jsonStrings.push_back(EntInformationString);
	}

//	for (std::string x : jsonStrings)
//	{
//		std::cout << x << std::endl;
//	}

	std::cout << AllEntInformationString << std::endl;


	try
	{
		http::Request request{ "http://localhost:3000" };
		const std::string body = AllEntInformationString;
		const auto response = request.send("POST", body, {
			{"Content-Type", "application/x-www-form-urlencoded"}
			});
		std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
	}
	catch (const std::exception& e)
	{
		std::cerr << "Request failed, error: " << e.what() << '\n';
	}

}

void PrintPlayerlistAndSendJSON() {

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

	//std::cout << AllEntInformationString << std::endl;

	// Sending the HTTP Request
	try
	{
		http::Request request{ "http://localhost:4000/set" };
		const std::string body = AllEntInformationString;
		const auto response = request.send("POST", body, {
			{"Content-Type", "application/json"}
			}, std::chrono::milliseconds(500));
		
		std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
	}
	catch (const std::exception& e)
	{
		std::cerr << "Request failed, error: " << e.what() << '\n';
	}

}


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