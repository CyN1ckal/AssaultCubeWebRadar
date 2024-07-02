#include "pch.h"

bool Console_Initialized = false;
bool CheatAlive = true;
Config config;

extern HMODULE g_hModule;


// Starting Thread
DWORD WINAPI StartingThread(HMODULE hModule)
{
    Console::AllocateConsole();

    Console_Initialized = true;

    config.GetModuleBaseAddress();

    Sleep(100);

    std::thread NetworkingThread(NetworkingLoop);

    while (CheatAlive)
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            CheatAlive = false;
        }
        Sleep(100);
    }

    printf("Cheat Dead\n");

    NetworkingThread.join();

    // Reminder; this will end up calling the DllMain function. We can do further cleanup from there.
    FreeLibraryAndExitThread(g_hModule, NULL);

    return 0;

}