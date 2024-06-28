#include "pch.h"

extern Config config;

void PrintPlayerCoords() {
	LocalPlayer* LocalPlayerAddress = (LocalPlayer*)*(uintptr_t*)(config.ac_clientBaseAddress + Offsets::LocalPlayerOffset);

	printf("\r");

	printf("x,y,z : %f,%f,%f", LocalPlayerAddress->Position.x, LocalPlayerAddress->Position.y, LocalPlayerAddress->Position.z);
}