#include "../include/Puncte.h"
#include "../include/Pachet.h"

void Puncte::init() {
    const Pachet& p = Pachet::getInstance();
    for (const std::vector<Carte>* c = p.getPachet(); auto& x: (*c)) {
        if (x.getRank() == ten)
            punctaj_carti[x] = 10;
        else if (x.getRank() == ace)
            punctaj_carti[x] = 11;
        else
            punctaj_carti[x] = x.getRank();
    }
}

void Puncte::set_pct(const Culoare a) {
    const Carte n(a, nine);
    const Carte v(a, jack);
    punctaj_carti[n] = 14;
    punctaj_carti[v] = 20;
}

std::map<Carte, int>* Puncte::getPct() {
    return &punctaj_carti;
}
