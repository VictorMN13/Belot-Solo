#pragma once
#include "ContainerCarti.h"
#include "Puncte.h"

class CardsWon final : public ContainerCarti {
public:
    CardsWon() = default;
    ~CardsWon() override = default;
    void set_card(std::vector<Carte>& c) {
        carti = &c;
    }
    std::vector<Carte>& get_carti() const {
        return *carti;
    }
    static int calcPuncte(const CardsWon& cards, Puncte& pct);
};
