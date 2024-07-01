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

    std::thread WorkerThread1(MainLoop);

    std::thread WorkerThread2(KeybindLoop);

    while (CheatAlive)
    {
        SendPlayerData();
        Sleep(25);
    }

    printf("Cheat Dead\n");

    WorkerThread1.join();

    WorkerThread2.join();


    // Reminder; this will end up calling the DllMain function. We can do further cleanup from there.
    FreeLibraryAndExitThread(g_hModule, NULL);

    return 0;

}