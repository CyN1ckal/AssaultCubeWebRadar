// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Global variables
HMODULE g_hModule = NULL;

bool Console_Initialized = false;

bool CheatAlive = true;

Config config;

// Starting Thread
DWORD WINAPI StartingThread(HMODULE hModule)
{
   Console::AllocateConsole();
 
   Console_Initialized = true;

   config.Initialize();

   Sleep(100);

    std::thread WorkerThread1(MainLoop);

    std::thread WorkerThread2(KeybindLoop);

    while (CheatAlive)
    {

    }

    std::cout << "Cheat Dead\n";

    WorkerThread1.join();

    WorkerThread2.join();

    // Reminder; this will end up calling the DllMain function. We can do further cleanup from there.
    FreeLibraryAndExitThread(g_hModule, NULL);

    return 0;

}

// DllMain
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    g_hModule = hModule;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)StartingThread, hModule, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
        if (!Console_Initialized) break;
        std::cout << "DLL_THREAD_ATTACH" << std::endl;
        break;
    case DLL_THREAD_DETACH:
        if (!Console_Initialized) break;
        std::cout << "DLL_THREAD_DETACH" << std::endl;
        break;
    case DLL_PROCESS_DETACH:
        if (!Console_Initialized) break;
        std::cout << "DLL_PROCESS_DETACH" << std::endl;
        Console::DetachConsole();
        break;
    }
    return TRUE;
}

