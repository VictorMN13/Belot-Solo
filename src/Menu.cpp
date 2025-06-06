#include "../include/Menu.h"
#include "../include/Utilities.h"
#include <fstream>
#include <limits>
#include <string>
#include <stdexcept>

Menu::~Menu() {
    for (const auto& x: log) {
        delete x;
    }
}

Menu& Menu::get_app() {
    static Menu menu;
    return menu;
}

void Menu::afisMenu() {
    Utilities::afisCentrat("Bine ai venit la Belot Solo");
    Utilities::afisCentrat("Cel mai bun joc de carti!");
    std::cout << '\n';
    Utilities::afisCentrat("Optiuni:");
    Utilities::afisCentrat("1. Reguli Belot");
    Utilities::afisCentrat("2. Joc Nou");
    Utilities::afisCentrat("3. Rezumat Ultim Joc");
    Utilities::afisCentrat("4. Exit");
}

void Menu::open() {
    int opt=5;
    while (opt!=4) {
        afisMenu();
        std::cin >> opt;
        switch (opt) {
            case 1: {
                afisareReguli();
                break;
            }
            case 2: {
                newGame();
                break;
            }
            case 3: {
                afisareLogJoc();
                break;
            }
            case 4: {
                break;
            }
            default: {
                std::cout << "Optiune invalida." << std::endl;
                break;
            }
        }
    }
}

void Menu::afisareReguli() {
    Utilities::clearScreen();
    try {
        std::string numeFisier = "Reguli_belot.txt";
        std::ifstream fisier(numeFisier);
        if (!fisier.is_open()) {
            throw std::runtime_error("Nu am putut deschide fisierul: " + numeFisier);
        }

        std::string linie;
        while (std::getline(fisier, linie)) {
            std::cout << linie << '\n';
        }

        fisier.close();
    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << '\n';
    }
    std::cout << "Apasati enter pentru a iesi";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // curăță bufferul
    std::cin.get();  // așteaptă Enter
    Utilities::clearScreen();
}

void Menu::newGame() {
    const auto j = new Joc();
    j->fullGame();
    this->log.clear();
    for (auto ptr : j->returnLog()) {
        this->log.push_back(new Istoric<int, std::vector<std::string>>(*ptr));
    }
    delete j;
}

void Menu::afisareLogJoc() const {
    if (log.empty()) {
        std::cout << "\nNu s a jucat inca nici un joc\n";
    } else {
        std::cout << "\nRezumatul ultimului joc:\n";
        for (const auto& x: log) {
            std::cout << "Runda " << x->getFirst() << "\n";
            for (const auto& y: x->getSecond()) {
                std::cout << "    " << y << "\n";
            }
        }
    }
    std::cout << "Apasati enter pentru a iesi";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // curăță bufferul
    std::cin.get();  // așteaptă Enter
    Utilities::clearScreen();
}


