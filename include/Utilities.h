#pragma once
#include <cstdlib>
#include "Carte.h"
#include "Puncte.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

class Utilities {
    Utilities() = delete;
    Utilities(const Utilities&) = delete;
    Utilities& operator=(const Utilities&) = delete;
    ~Utilities() = delete;
public:
    static bool bate(Culoare& atu , const Carte& a, const Carte& b, const Culoare& obl, Puncte& puncte);
    static void clearScreen();
    static int getTerminalWidth();
    static void afisCentrat(const std::string&);
};
