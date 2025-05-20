#pragma once
#include "Player.h"

class Bot: public Player {
public:
    explicit Bot(std::unique_ptr<AtuStrategy> atu_strategy, std::unique_ptr<JoacaStrategy> joaca_strategy, std::string name = "Bot Unknown"): Player(std::move(atu_strategy), std::move(joaca_strategy), name) {};
    ~Bot() override = default;
    bool joacaAtu(Culoare) override;
    Culoare alegeAtu(int) override;
    Carte joaca(std::vector<Carte>&, bool, Puncte&, Culoare atu, int) override;
};
