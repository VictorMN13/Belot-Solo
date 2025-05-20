#include "../include/Om.h"
#include <unordered_map>

bool Om::joacaAtu(Culoare c) {
    int aux;
    std::cout << "Joci acest atu?\n";
    std::cin >> aux;
    return aux!=0;
}

void Om::afisareHand() {
    std::cout << hand;
}

Culoare Om::alegeAtu(int d) {
    return atu_strategy->alegere(*getPHand(), d, this->id);
}

Carte Om::joaca(std::vector<Carte>& pe_masa, bool atu_free, Puncte& pct, Culoare atu, int decl) {
    Carte aux;
    aux = joaca_strategy->miscare(pe_masa, atu_free, pct, atu, hand, id, decl);
    return aux;
}



