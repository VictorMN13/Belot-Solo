#pragma once
#include "Player.h"
#include "PlayHand.h"

class Bot: public Player {
    PlayHand cards_played;
public:
    explicit Bot(const std::string& _name = "Bot_default"): Player(_name) {};
    ~Bot() {};
    bool joacaAtu(Culoare) override;
    Culoare alegeAtu(int) override;
};
