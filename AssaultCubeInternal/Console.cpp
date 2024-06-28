#include "pch.h"

FILE* f;

void Console::AllocateConsole()
{
    AllocConsole();

    // Without this sleep the console will not print on the first launch. I don't entirely understand why.
    // I assume it is because I am trying to redirect the stdout before the console is fully done allocating... So 50ms wait it is.
    Sleep(50);

    // Redirecting the stdout to our f file.
    freopen_s(&f, "CONOUT$", "w", stdout);
}


void Console::DetachConsole()
{
    FreeConsole();

    // To-Do: Redirect the stdout back to the original.
    // In this case it dosen't matter cause AC dosent have a console open; but it might matter for other games.
    // I think it will end up causing stdout's to go into the void after the DLL is ejected; lol.
}