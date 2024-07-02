#pragma once

struct Config
{
	uintptr_t ac_clientBaseAddress = NULL;

	void GetModuleBaseAddress()
	{
		ac_clientBaseAddress = (uintptr_t)GetModuleHandle(NULL);
	}
};