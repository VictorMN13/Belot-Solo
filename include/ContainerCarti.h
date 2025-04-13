#pragma once
#include <vector>
#include "Carte.h"

class ContainerCarti {
protected:
    std::vector<Carte>* carti;
    ContainerCarti() {
        std::cout << "Container_carti::Container_carti()" << std::endl;
    };
    virtual ~ContainerCarti() {
        std::cout << "Container_carti::~Container_carti()" << std::endl;
    };
    std::vector<Carte>* getContainer() const;
public:
    friend std::ostream& operator<<(std::ostream& os, const ContainerCarti& container);
};

