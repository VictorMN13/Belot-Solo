#pragma once
#include "ContainerCarti.h"


class Pachet: public ContainerCarti {
    Pachet();
    ~Pachet();
public:
    Pachet(const Pachet&) = delete;
    Pachet& operator=(const Pachet&) = delete;
    static Pachet& getInstance();
    [[nodiscard]] std::vector<Carte>* getPachet() const;
    static void amestecare(std::vector<Carte>*);
    static void taiere(std::vector<Carte>* carti, int x);
    friend std::ostream& operator<<(std::ostream& os, const Pachet& pachet);
};


