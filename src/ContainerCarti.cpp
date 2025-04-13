#include "../include/ContainerCarti.h"

std::ostream& operator<<(std::ostream& os, const ContainerCarti& container_carti) {
    for (int i = container_carti.carti->size() - 1; i >= 0; i--) {
        os << (*container_carti.carti)[i] << " ";
    }
    return os;
}

std::vector<Carte>* ContainerCarti::getContainer() const {
    return carti;
}