#include "../include/Bot.h"
#include <map>
#include <optional>

bool Bot::joacaAtu(Culoare c) {
    int count = 0;
    for (const auto& carte : (*hand.getHand())) {
        if (carte.getCuloare() == c)
            count++;
    }
    return count >= 2;
}

Culoare Bot::alegeAtu(int id) {
    std::map<Culoare, int> frecv;
    for (const auto& carte : (*hand.getHand())) {
        frecv[carte.getCuloare()]++;
    }
    int maxC = 0;
    Culoare c;
    for (auto x : frecv) {
        if (x.second > maxC) {
            maxC = x.second;
            c = x.first;
        }
    }
    if (maxC>=3)
        return c;
    else if (id == this->id)
        return c;
    else
        return Culoare::none;
}


