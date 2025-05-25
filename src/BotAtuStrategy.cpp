#include "../include/BotAtuStrategy.h"
#include <map>

Culoare BotAtuStrategy::alegere(const PlayHand &hand, const int idDealer, const int idPlayer) {
    std::map<Culoare, int> frecv;
    for (const auto& carte : (*hand.getHand())) {
        frecv[carte.getCuloare()]++;
    }
    int maxC = 0;
    Culoare c = none;
    for (auto x : frecv) {
        if (x.second > maxC) {
            maxC = x.second;
            c = x.first;
        }
    }
    if ((maxC>=3) || (idDealer == idPlayer))
        return c;
    else
        return Culoare::none;
}

bool BotAtuStrategy::jucare(const Culoare c, PlayHand &hand) {
    int count = 0;
    for (const auto& carte : (*hand.getHand())) {
        if (carte.getCuloare() == c)
            count++;
    }
    return count >= 3;
}

