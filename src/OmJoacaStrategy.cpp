#include "../include/OmJoacaStrategy.h"

#include "Exceptii.h"

Carte OmJoacaStrategy::miscare(std::vector<Carte> &pe_masa, bool atu_free, Puncte &pct, Culoare atu, PlayHand &hand, int id, int decl) {
    std::vector<Carte>& c = *hand.getHand();
    std::map<Culoare, int> frecv;
    for (const auto& carte : c) {
        frecv[carte.getCuloare()]++;
    }
    std::cout<< "Ce carte joci? Alege numarul cartii de la 1 la " << c.size() << "\n";
    int x; std::cin >> x;

    if (x < 1 || x > static_cast<int>(c.size())) {
        throw InputExceptionJoaca();
    }



    Carte aux = c[x-1];
    c.erase(c.begin()+x-1);
    return aux;
}
