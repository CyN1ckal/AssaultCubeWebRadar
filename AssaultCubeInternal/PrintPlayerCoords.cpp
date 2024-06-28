#include "pch.h"

extern Config config;

void PrintPlayerCoords() {
	LocalPlayer* LocalPlayerAddress = (LocalPlayer*)*(uintptr_t*)(config.ac_clientBaseAddress + 0x10F4F4);

	printf("x,y,z : %f,%f,%f", LocalPlayerAddress->Position.x, LocalPlayerAddress->Position.y, LocalPlayerAddress->Position.z);

	printf("\r");
}