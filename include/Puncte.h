#pragma once
#include <map>
#include "Carte.h"

class Puncte {
    std::map<Carte, int> punctaj_carti;
public:
    Puncte() = default;
    ~Puncte() = default;
    void init();
    void set_pct(Culoare a);
    std::map<Carte, int>* getPct();
};