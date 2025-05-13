#pragma once
#include "Player.h"

class Om: public Player {
public:
    explicit Om(const std::string& _name = "Om"): Player(_name) {};
    ~Om() {};
    bool joacaAtu(Culoare) override;
    void afisareHand();
    Culoare alegeAtu(int) override;
};
