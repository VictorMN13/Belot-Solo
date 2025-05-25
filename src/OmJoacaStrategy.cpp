#include "../include/OmJoacaStrategy.h"

#include "Exceptii.h"

Carte OmJoacaStrategy::miscare(std::vector<Carte> &pe_masa, bool atu_free, Puncte &pct, Culoare atu, PlayHand &hand, int id, int decl) {
    std::vector<Carte>& c = *hand.getHand();
    std::map<Culoare, int> frecv;
    for (const auto& carte : c) {
        frecv[carte.getCuloare()]++;
    }
    int x; std::cin >> x;

    if (x < 1 || x > static_cast<int>(c.size())) {
        throw InputExceptionJoaca();
    }

    Carte aux = c[x-1];

    if (id != decl && !atu_free && aux.getCuloare() == atu && frecv.size() > 1 && frecv[atu] != static_cast<int>(c.size())) {
        throw AtuFreeException();
    }

    if (!pe_masa.empty()) {
        Culoare culoare_req = pe_masa[0].getCuloare();
        if ((aux.getCuloare() != culoare_req && frecv[culoare_req] > 0) ||
            (aux.getCuloare() != atu && (frecv[atu] > 0 && frecv[culoare_req] == 0))) {
            throw CuloareInvalidException();
        }
    }

    c.erase(c.begin()+x-1);
    return aux;
}
