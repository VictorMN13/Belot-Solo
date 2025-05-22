#include "../include/CardsWon.h"

int CardsWon::calcPuncte(CardsWon& cards, Puncte& pct) {
    int x=0;
    std::map<Carte, int>& p = *pct.getPct();
    std::vector<Carte> c = cards.get_carti();
    for (Carte& carte: c)
        x+=p[carte];
    return x;
}
