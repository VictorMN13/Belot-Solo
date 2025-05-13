#include "../include/PlayHand.h"
#include <algorithm>

PlayHand::PlayHand() {
    carti->reserve(8);
}

void PlayHand::add(const Carte x) {
    carti->push_back(x);
}

PlayHand::~PlayHand() {
    //delete carti;
}

void PlayHand::aranjare(std::vector<Carte>* carti) {
    std::sort(carti->begin(), carti->end());
}

std::vector<Carte>* PlayHand::getHand() const{
    return this->getContainer();
};

