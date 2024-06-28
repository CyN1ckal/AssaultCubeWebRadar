#include "pch.h"

FILE* f;

void Console::AllocateConsole()
{
    AllocConsole();

    Sleep(50);

    freopen_s(&f, "CONOUT$", "w", stdout);
}

void Console::DetachConsole()
{
    FreeConsole();
}