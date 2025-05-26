#include "../include/CardsWon.h"

int CardsWon::calcPuncte(const CardsWon& cards, Puncte& pct) {
    int x=0;
    for (std::vector<Carte> c = cards.get_carti(); Carte& carte: c)
        x+=(*pct.getPct())[carte];
    return x;
}
