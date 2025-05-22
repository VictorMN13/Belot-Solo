#include "../include/Bot.h"

bool Bot::joacaAtu(const Culoare c) {
    return atu_strategy->jucare(c, hand);
}

Culoare Bot::alegeAtu(int id) {
    return atu_strategy->alegere(*getPHand(), id, this->id);
}

Carte Bot::joaca(std::vector<Carte>& pe_masa, bool atu_free, Puncte& pct, Culoare atu, int decl) {
    Carte aux;
    aux = joaca_strategy->miscare(pe_masa, atu_free, pct, atu, hand, id, decl);
    return aux;
}


