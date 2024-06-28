#include "pch.h"

extern bool CheatAlive;

extern Config config;

void MainLoop()
{

    std::cout << "Starting Main Loop\n";

    while (CheatAlive)
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            CheatAlive = false;
            break;
        }

        if (GetAsyncKeyState(VK_INSERT) & 1) PrintPlayerlist();

        if(config.bRefreshHealth) RefreshHealth();

        if (config.bPrintPlayerCoords) PrintPlayerCoords();
    }

}
