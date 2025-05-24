#pragma once
#include <iostream>
#include "Joc.h"

class Menu {
private:
    std::vector<Istoric<int, std::vector<std::string>>*> log;
    Menu() = default;
    ~Menu() = default;
public:
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    static Menu& get_app();
    void open();
    void afisMenu();
    void afisareReguli();
    void newGame();
    void afisareLogJoc();
};