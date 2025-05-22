#pragma once
#include "AtuStrategy.h"

class BotAtuStrategy: public AtuStrategy {
    public:
    BotAtuStrategy() = default;
    ~BotAtuStrategy() override = default;
    Culoare alegere(const PlayHand &hand, int idDealer, int idPlayer) override;
    bool jucare(const Culoare c, PlayHand&) override;
};
