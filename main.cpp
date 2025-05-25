#include <iostream>
#include "include/Joc.h"
#include "include/Menu.h"

int main() {
    auto& meniu = Menu::get_app();
    meniu.open();
}
