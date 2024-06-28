#include "pch.h"

void RefreshHealth()
{
	// Getting Base Address of ac_client.exe 
	uintptr_t ModuleBaseAddress = (uintptr_t)GetModuleHandle(NULL);

	// Getting Base Address of Player; ac_client.exe + 0x10F4F4
	uintptr_t* PlayerBaseAddress = (uintptr_t*)(ModuleBaseAddress + 0x10F4F4);

	// Setting Health Address (PlayerBaseAddress+0xF8) to 1000.
	*(int*)(*PlayerBaseAddress + 0xF8) = 1000;
}