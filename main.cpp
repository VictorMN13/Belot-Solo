#include <iostream>
#include "include/Joc.h"
#include "include/Menu.h"

int main() {
    // Joc j;
    // j.fullGame();
    auto& meniu = Menu::get_app();
    meniu.open();
}
