#include "../include/Om.h"

bool Om::joacaAtu(Culoare c) {
    int aux;
    std::cout << "Joci acest atu?\n";
    std::cin >> aux;
    return aux!=0;
}

void Om::afisareHand() {
    std::cout << hand;
}

Culoare Om::alegeAtu(int) {
    return Culoare::pica;
}

