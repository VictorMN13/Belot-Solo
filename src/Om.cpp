#include "../include/Om.h"
#include <exception>
#include <limits>
#include "../include/OmAtuStrategy.h"

bool Om::joacaAtu(Culoare c) {
    if (dynamic_cast<OmAtuStrategy*>(atu_strategy.get()) != nullptr) {
        std::cout << "Cartile tale: " << hand << "\n";
        std::cout << "Joci acest atu?\n";
    }
    while (true) {
        try {
            return atu_strategy->jucare(c, hand);
        }
        catch (std::exception &e) {
            std::cout << "Eroare " << e.what() << "\nMai incearca\n";
        }
    }
}

Culoare Om::alegeAtu(int d) {
    if (dynamic_cast<OmAtuStrategy*>(atu_strategy.get()) != nullptr) {
        std::cout << "Cartile tale: " << hand << "\n";
        std::cout << "Alege atu sau da pass\n";
        if (this->id == d) {
            std::cout << "Sunteti obligat sa alegeti un atu si sa jucati runda\n";
        }
        std::cout << "Optiuni\n";
        std::cout << "1 - pica\n";
        std::cout << "2 - trefla\n";
        std::cout << "3 - diamant\n";
        std::cout << "4 - inima\n";
        std::cout << "0 - niciun atu (pass)\n";
    }
    while (true) {
        try {
            return atu_strategy->alegere(*getPHand(), d, this->id);
        }
        catch (const std::exception& e) {
            std::cout << "Eroare: " << e.what() << "\nTe rog incearca din nou.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

Carte Om::joaca(std::vector<Carte>& pe_masa, bool atu_free, Puncte& pct, Culoare atu, int decl) {
    if (dynamic_cast<OmAtuStrategy*>(atu_strategy.get()) != nullptr) {
        ContainerCarti::aranjare(hand);
        if (pe_masa.empty()) {
            std::cout << "Nu sunt carti pe masa\n";
        } else {
            std::cout << "\nCartile de pe masa:\n";
            for (auto x : pe_masa) {
                std::cout << x << " ";
            }
            std::cout << "\n";
        }

        std::cout<< "Ce carte joci? Alege numarul cartii de la 1 la " << hand.getHand()->size() << "\n";
        std::cout << hand << "\n";
    }

    while (true) {
        try {
            return joaca_strategy->miscare(pe_masa, atu_free, pct, atu, hand, id, decl);
        }
        catch (std::exception& e) {
            std::cout << "Eroare: " << e.what() << "\nTe rog incearca din nou.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

}



