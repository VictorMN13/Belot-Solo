#pragma once
#include "Carte.h"
#include "PlayHand.h"
#include "Puncte.h"
//#include "Utilities.h"

class JoacaStrategy {
public:
    JoacaStrategy() = default;
    virtual ~JoacaStrategy() = default;
    virtual Carte miscare(std::vector<Carte>&, bool, Puncte&, Culoare, PlayHand&, int, int) = 0;
};