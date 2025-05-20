#pragma once
#include "Carte.h"
#include "PlayHand.h"

class AtuStrategy {
    public:
    AtuStrategy() = default;
    virtual ~AtuStrategy() = default;
    virtual Culoare alegere(const PlayHand& hand, int idDealer, int idPlayer) = 0;
};