#pragma once
#include "ContainerCarti.h"

class PlayHand: public ContainerCarti {
public:
    PlayHand();
    ~PlayHand();
    static void aranjare(std::vector<Carte>*);
};
