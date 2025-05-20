#pragma once
#include "Player.h"

class Om: public Player {
public:
    explicit Om(std::unique_ptr<AtuStrategy> atu_strategy, std::unique_ptr<JoacaStrategy> joaca_strategy, std::string name = "Om Unknown"): Player(std::move(atu_strategy), std::move(joaca_strategy), name) {};
    ~Om() {};
    bool joacaAtu(Culoare) override;
    void afisareHand();
    Culoare alegeAtu(int) override;
    Carte joaca(std::vector<Carte>&, bool, Puncte&, Culoare atu, int) override;
};
