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

void PrintPlayerlistAndSendJSON() {

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
		http::Request request{ "http://10.0.0.3:3000" };
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