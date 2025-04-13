#pragma once
#include "ContainerCarti.h"


class Pachet: public ContainerCarti {
public:
    Pachet();
    ~Pachet();
    std::vector<Carte>* getPachet() const;
    static void amestecare(std::vector<Carte>*);
    static void taiere(std::vector<Carte>* carti, int x);
};

