#include "../include/OmJoacaStrategy.h"

Carte OmJoacaStrategy::miscare(std::vector<Carte> &pe_masa, bool atu_free, Puncte &pct, Culoare atu, PlayHand &hand, int id, int decl) {
    std::vector<Carte>& c = *hand.getHand();
    std::cout<< "Ce carte joci? Alege numarul cartii de la 1 la " << c.size() << "\n";
    int x; std::cin >> x;
    //tratare exceptii cu carti invalide etc;
    Carte aux = c[x-1];
    c.erase(c.begin()+x-1);
    return aux;
}
