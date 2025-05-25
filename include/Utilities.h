#pragma once
#include "Carte.h"
#include "Puncte.h"
#ifdef _WIN32
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
    static bool bate(const Culoare& atu , const Carte& a, const Carte& b, const Culoare& obl, Puncte& puncte);
    static void clearScreen();
    static int getTerminalWidth();
    static void afisCentrat(const std::string&);
};
