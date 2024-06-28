#include "pch.h"

extern Config config;

void RefreshHealth()
{
	// Getting Address of LocalPlayer and making it a Re-Class struct
	LocalPlayer* PlayerBaseAddress = (LocalPlayer*)*(uintptr_t*)(config.ac_clientBaseAddress + Offsets::LocalPlayerOffset);

	PlayerBaseAddress->PlayerHealth = 1000;
}