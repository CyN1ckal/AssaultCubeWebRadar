#include "pch.h"

FILE* f;

void Console::AllocateConsole()
{
    AllocConsole();

    freopen_s(&f, "CONOUT$", "w", stdout);
}

void Console::DetachConsole()
{
    FreeConsole();
}