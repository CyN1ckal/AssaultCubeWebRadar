#include "pch.h"

void RefreshHealth()
{
	uintptr_t ModuleBaseAddress = (uintptr_t)GetModuleHandle(NULL);
	uintptr_t* PlayerBaseAddress = (uintptr_t*)(ModuleBaseAddress + 0x10F4F4);
	std::cout << std::hex << *PlayerBaseAddress << std::endl;
	*(int*)(*PlayerBaseAddress + 0xF8) = 1000;
}