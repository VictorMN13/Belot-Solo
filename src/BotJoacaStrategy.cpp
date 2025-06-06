#include "../include/BotJoacaStrategy.h"
#include <algorithm>
#include <ranges>
#include "../include/Utilities.h"

Carte BotJoacaStrategy::miscare(std::vector<Carte> &pe_masa, const bool atu_free, Puncte &pct, const Culoare atu, PlayHand &hand, const int id, const int decl) {
    std::map<Carte, int> p = *pct.getPct();
    std::vector<Carte>& c = *hand.getHand();
    std::ranges::sort(c, [&](const Carte& a, const Carte& b) {
        return p[a] > p[b];
    });
    std::map<Culoare, int> frecv;
    for (const auto& carte : c) {
        frecv[carte.getCuloare()]++;
    }
    if (pe_masa.empty()) { // daca el incepe turul
        Carte aux = c.front();
        auto poz = c.begin();
        if (!atu_free && id!=decl) {
            for (auto it = c.begin(); it != c.end(); ++it) {
                if (it->getCuloare() != atu) {
                    aux = *it;
                    poz = it;
                    break;
                }
            }
        }
        c.erase(poz);
        return aux;
    }
    std::vector<Carte> optiuni;
    const Culoare obl = pe_masa[0].getCuloare();
    if (frecv[obl] > 0) {
        for (auto& x: c) {
            if (x.getCuloare() == obl)
                optiuni.push_back(x);
        }
    } else optiuni = c;
    std::ranges::sort(optiuni, [&](const Carte& a, const Carte& b) {
        if (a.getCuloare() == atu && b.getCuloare() != atu) return true; // a e atu, b nu e
        if (a.getCuloare() != atu && b.getCuloare() == atu) return false; // b e atu, a nu e
        // Daca ambele sunt atu sau niciuna ordonez dupa punctaj:
        return p[a] > p[b];
    });
    Carte aux = optiuni.front();
    if (aux.getCuloare() == obl) {
        const bool maxim_pct = std::ranges::all_of(pe_masa, [&](const Carte& x) {
            return Utilities::bate(atu, aux, x, obl, pct);
        });
        if (!maxim_pct)
            aux = optiuni.back();
    } else
        if (aux.getCuloare() != atu)
            aux =  optiuni.back();
    const auto poz = std::ranges::find(c, aux);
    c.erase(poz);
    return aux;
};