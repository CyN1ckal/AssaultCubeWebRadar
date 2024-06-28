// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

bool DLL_Initialized = false;
bool CheatAlive = true;

HMODULE g_hModule = NULL;
uintptr_t ModuleBaseAddress = NULL;

DWORD WINAPI StartingThread(HMODULE hModule)
{
    DLL_Initialized = true;

   Console::AllocateConsole();

   std::cout << "Starting Thread Hit\n";

    ModuleBaseAddress = (uintptr_t)GetModuleHandle(NULL);

    std::thread WorkerThread1(MainLoop);

    while (CheatAlive)
    {
        std::cout << "Starting Thread Loop" << std::endl;
        Sleep(1000);
    }

    std::cout << "Cheat Dead\n";

    WorkerThread1.join();

    // Reminder; this will end up calling the DLL main function. We can do further cleanup from there.
    FreeLibraryAndExitThread(g_hModule, NULL);

    return 0;
}


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
        if (!DLL_Initialized) break;
        std::cout << "Thread Attach" << std::endl;
        break;
    case DLL_THREAD_DETACH:
        if (!DLL_Initialized) break;
        std::cout << "Thread Detach" << std::endl;
        break;
    case DLL_PROCESS_DETACH:
        if (!DLL_Initialized) break;
        std::cout << "Process Detaching" << std::endl;
        Console::DetachConsole();
        break;
    }
    return TRUE;
}

