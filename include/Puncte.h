#pragma once
#include <iostream>
#include <map>
#include "Carte.h"
#include "Pachet.h"

class Puncte {
    std::map<Carte, int> punctaj_carti;
public:
    Puncte() = default;
    ~Puncte() = default;
    void init();
    void set_pct(Culoare a);
    std::map<Carte, int>* getPct();
};