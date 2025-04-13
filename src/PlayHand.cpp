#include "../include/PlayHand.h"
#include <algorithm>

PlayHand::PlayHand() {
    carti = new std::vector<Carte>;
    carti->reserve(6);
}

PlayHand::~PlayHand() {
    delete carti;
}

void PlayHand::aranjare(std::vector<Carte>* carti) {
    std::sort(carti->begin(), carti->end());
}

