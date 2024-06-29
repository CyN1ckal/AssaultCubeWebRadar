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

        if(config.bRefreshHealth) RefreshHealth();

        if (config.bPrintPlayerCoords) PrintPlayerCoords();

        if(config.bSendRadarData) PrintPlayerlistAndSendJSON();
 
    }

}
