#pragma once
#include "ContainerCarti.h"

class PlayHand final : public ContainerCarti {
public:
    PlayHand();
    ~PlayHand() override;
    //static void aranjare(std::vector<Carte>*);
    void add(Carte) const;
    [[nodiscard]] std::vector<Carte>* getHand() const;
};
