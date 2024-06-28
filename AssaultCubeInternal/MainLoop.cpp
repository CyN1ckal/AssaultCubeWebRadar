#include "pch.h"

#include "InfiniteHealth.h"

extern bool CheatAlive;

extern Config config;

void MainLoop()
{

    std::cout << "Starting Main Loop\n";

    while (CheatAlive)
    {

        if(config.bRefreshHealth) RefreshHealth();

        if (config.bPrintPlayerCoords) PrintPlayerCoords();

        if (GetAsyncKeyState(VK_END) & 1)
        {
            CheatAlive = false;
        }

    }

}
