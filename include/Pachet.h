#pragma once
#include <vector>
#include "Carte.h"


class Pachet {
    std::vector<Carte>* carti;
public:
    Pachet();
    ~Pachet();
    std::vector<Carte>* getPachet() const;
    static void amestecare(std::vector<Carte>*);
    friend std::ostream& operator<<(std::ostream& os, const Pachet& pachet);
};

