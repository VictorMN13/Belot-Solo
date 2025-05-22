#pragma once
#include "ContainerCarti.h"

class PlayHand: public ContainerCarti {
public:
    PlayHand();
    ~PlayHand() override;
    //static void aranjare(std::vector<Carte>*);
    void add(Carte);
    [[nodiscard]] std::vector<Carte>* getHand() const;
};
