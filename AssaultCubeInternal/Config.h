#pragma once

struct Config
{
	uintptr_t ac_clientBaseAddress = NULL;


	bool bRefreshHealth = false;
	bool bPrintPlayerCoords = false;
	bool bSendRadarData = false;

	void GetModuleBaseAddress()
	{
		ac_clientBaseAddress = (uintptr_t)GetModuleHandle(NULL);
	}
};