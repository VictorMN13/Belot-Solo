#pragma once
#include <vector>
#include "Player.h"
#include "Carte.h"

class Runda {
    std::vector<Player*> players;
    Culoare atu;
    int dealer;
    int declarant = -1;
public:
    Runda(const std::vector<Player*> &, int);
    ~Runda() = default;
    static void setAtu(Runda&, Culoare);
    static void setDeclarant(Runda&, int);
    static void impartireCarti(Runda&);
};