#pragma once
#include "ContainerCarti.h"

class CardsWon: public ContainerCarti {
public:
    CardsWon() = default;
    ~CardsWon() override = default;
    void set_card(std::vector<Carte>& c) {
        carti = &c;
    }
    std::vector<Carte>& get_carti() {
        return *carti;
    }
    static void calcPuncte();
};
