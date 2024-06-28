#include "pch.h"

extern Config config;

void RefreshHealth()
{
	// Getting Address of LocalPlayer and making it a Re-Class struct
	LocalPlayer* PlayerBaseAddress = (LocalPlayer*)*(uintptr_t*)(config.ac_clientBaseAddress + 0x10F4F4);

	PlayerBaseAddress->PlayerHealth = 1000;
}