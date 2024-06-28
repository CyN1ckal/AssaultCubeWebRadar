#include "pch.h"

#include "InfiniteHealth.h"

extern bool CheatAlive;

void MainLoop()
{
    std::cout << "In Main Loop\n";
    while (CheatAlive)
    {
        std::cout << "Main Loop\n";
        Sleep(1000);
        RefreshHealth();
        if (GetAsyncKeyState(VK_END) & 1)
        {
            CheatAlive = false;
        }
    }
}
