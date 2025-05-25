#pragma once
#include "Player.h"

class Om final : public Player {
public:
    explicit Om(std::unique_ptr<AtuStrategy> atu_strategy, std::unique_ptr<JoacaStrategy> joaca_strategy, const std::string &name = "Om Unknown"): Player(std::move(atu_strategy), std::move(joaca_strategy), name) {};
    ~Om() override {};
    bool joacaAtu(Culoare) override;
    void afisareHand() const;
    Culoare alegeAtu(int) override;
    Carte joaca(std::vector<Carte>&, bool, Puncte&, Culoare atu, int) override;
};
