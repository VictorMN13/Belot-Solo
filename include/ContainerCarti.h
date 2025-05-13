#pragma once
#include <vector>
#include "Carte.h"

class ContainerCarti {
protected:
    std::vector<Carte>* carti;
    ContainerCarti(): carti(new std::vector<Carte>){
        std::cout << "Container_carti::Container_carti()" << std::endl;
    };
    virtual ~ContainerCarti() {
        delete carti;
        std::cout << "Container_carti::~Container_carti()" << std::endl;
    };
    ContainerCarti(const ContainerCarti& other);
    std::vector<Carte>* getContainer() const;
public:
    friend std::ostream& operator<<(std::ostream& os, const ContainerCarti& container);
    ContainerCarti& operator=(const ContainerCarti& other);
    ContainerCarti& operator+=(const ContainerCarti& other);
};

