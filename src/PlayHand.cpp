#include "../include/PlayHand.h"


PlayHand::PlayHand() {
    carti->reserve(8);
}

void PlayHand::add(const Carte x) const {
    carti->push_back(x);
}

PlayHand::~PlayHand() {}

std::vector<Carte>* PlayHand::getHand() const{
    return this->getContainer();
};

