#pragma once
#include <vector>
#include "Player.h"
#include "Carte.h"
#include "Puncte.h"
#include "Utilities.h"
#include <cmath>

class Runda {
    std::vector<Player*> players;
    Culoare atu;
    int dealer;
    int declarant = -1;
    Puncte puncte;
    std::vector<std::string> log;
public:
    Runda(const std::vector<Player*> &, int);
    ~Runda() = default;
    static void setAtu(Runda&, Culoare);
    static void setDeclarant(Runda&, int);
    static void impartireCarti(Runda&);
    static void afisPctRunda(Runda&);
    static int tur(Runda&, int);
    void desfasoara();
    void rezultate();
    static void returnareCarti(Runda&);
};