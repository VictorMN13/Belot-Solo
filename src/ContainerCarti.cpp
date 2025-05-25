#include "../include/ContainerCarti.h"

#include <algorithm>

std::ostream& operator<<(std::ostream& os, const ContainerCarti& container) {
    for (int i = 0; i <= container.carti->size() - 1; i++) {
        os << (*container.carti)[i] << " ";
    }
    return os;
}

std::vector<Carte>* ContainerCarti::getContainer() const {
    return carti;
}
ContainerCarti::ContainerCarti(const ContainerCarti &other): carti(new std::vector<Carte>) {
    if (other.carti != nullptr) {
        carti->reserve(other.carti->size());
        for (int i = 0; i <= other.carti->size() - 1; i++) {
            carti->push_back((*other.carti)[i]);
        }
    }
}

ContainerCarti& ContainerCarti::operator=(const ContainerCarti &other) {
    if (this == &other)
        return *this;
    else {
        if (other.carti != nullptr) {
            carti->clear();
            carti->reserve(other.carti->size());
            for (int i = 0; i <= other.carti->size() - 1; i++) {
                carti->push_back((*other.carti)[i]);
            }
        }
    }
    return *this;
}

ContainerCarti& ContainerCarti::operator+=(const ContainerCarti &other) {
    if (other.carti != nullptr) {
        for (int i = 0; i <= other.carti->size() - 1; i++) {
            carti->push_back((*other.carti)[i]);
        }
    }
    return *this;
}

void ContainerCarti::aranjare(const ContainerCarti &container) {
    std::vector<Carte>* c = container.getContainer();
    std::sort(c->begin(), c->end());
}
