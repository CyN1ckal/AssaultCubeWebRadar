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