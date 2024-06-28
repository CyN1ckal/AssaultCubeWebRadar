// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Global variables
HMODULE g_hModule = NULL;
extern bool Console_Initialized;

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

