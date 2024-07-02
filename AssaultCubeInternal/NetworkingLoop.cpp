#include "pch.h"

extern bool CheatAlive;

void NetworkingLoop()
{
	while (CheatAlive)
	{
		SendPlayerData();
		Sleep(25);
	}
}