#include "../include/CardsWon.h"

int CardsWon::calcPuncte(const CardsWon& cards, Puncte& pct) {
    int x=0;
    std::map<Carte, int>& p = *pct.getPct();
    for (std::vector<Carte> c = cards.get_carti(); Carte& carte: c)
        x+=p[carte];
    return x;
}
