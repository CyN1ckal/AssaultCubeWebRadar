#include "pch.h"

extern Config config;

void PrintPlayerlist() {

	uintptr_t EntityListBase = *(uintptr_t*)(config.ac_clientBaseAddress + Offsets::EntityListOffset);
	
	int PlayerCount = *(int*)(config.ac_clientBaseAddress + Offsets::PlayerCountOffset);

	printf("%d\n", PlayerCount);

	for (int i = 0; i < PlayerCount-1 ; i++)
	{
		printf("\n");

		uintptr_t NextEntAddress = (EntityListBase + 0x4) + (0x4 * i);

		printf("%X\n", NextEntAddress);

		LocalPlayer* ent = (LocalPlayer*)*(uintptr_t*)NextEntAddress;

		printf("Name,x,y : %s,%f,%f\n", ent->Name,ent->Position.x, ent->Position.y);
	}
}