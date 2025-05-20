#pragma once
#include "AtuStrategy.h"

class OmAtuStrategy: public AtuStrategy {
public:
    OmAtuStrategy() = default;
    ~OmAtuStrategy() override = default;
    Culoare alegere(const PlayHand &hand, int idDealer, int idPlayer) override;
};
