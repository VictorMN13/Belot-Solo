#pragma once
#include "JoacaStrategy.h"

class OmJoacaStrategy final : public JoacaStrategy {
public:
    OmJoacaStrategy() = default;
    ~OmJoacaStrategy() override = default;
    Carte miscare(std::vector<Carte> &, bool, Puncte &, Culoare, PlayHand &, int, int) override;
};