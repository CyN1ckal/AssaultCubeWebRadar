#pragma once

struct Config
{
	uintptr_t ac_clientBaseAddress = NULL;

	bool bRefreshHealth = false;
	bool bPrintPlayerCoords = false;

	void Initialize()
	{
		ac_clientBaseAddress = (uintptr_t)GetModuleHandle(NULL);
	}
};