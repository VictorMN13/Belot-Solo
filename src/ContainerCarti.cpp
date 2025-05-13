#include "../include/ContainerCarti.h"

std::ostream& operator<<(std::ostream& os, const ContainerCarti& container_carti) {
    for (int i = 0; i <= container_carti.carti->size() - 1; i++) {
        os << (*container_carti.carti)[i] << " ";
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
