#pragma once
#include "JoacaStrategy.h"

class BotJoacaStrategy final : public JoacaStrategy {
public:
    BotJoacaStrategy() = default;
    ~BotJoacaStrategy() override = default;
    Carte miscare(std::vector<Carte> &, bool, Puncte &, Culoare, PlayHand &, int, int) override;
};
