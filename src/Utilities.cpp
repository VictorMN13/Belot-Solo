#include "../include/Utilities.h"
#include <windows.h>

bool Utilities::bate(const Culoare &atu, const Carte &a, const Carte &b, const Culoare &obl, Puncte &puncte) {
    const bool a_atu = a.getCuloare() == atu;
    const bool b_atu = b.getCuloare() == atu;
    if (a_atu && !b_atu)
        return true;
    if (!a_atu && b_atu)
        return false;
    if ((a.getCuloare()==obl && b.getCuloare()==obl) || b_atu)
        return puncte.getPct()->at(a) > puncte.getPct()->at(b);
    if (a.getCuloare()==obl)
        return true;
    else return false;
}

void Utilities::clearScreen() {
#ifdef _WIN32
    std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    std::system("clear");
#else
    // Dacă sistemul de operare nu este recunoscut, se trimit caractere speciale ANSI
    std::cout << "\033[2J\033[1;1H";
#endif
}

int Utilities::getTerminalWidth() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width = 80; // fallback
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return width;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
#endif
}

void Utilities::afisCentrat(const std::string& linie) {
    int latime = getTerminalWidth();
    int spatii = (latime - linie.size()) / 2;
    if (spatii > 0) std::cout << std::string(spatii, ' ');
    std::cout << linie << '\n';
}


