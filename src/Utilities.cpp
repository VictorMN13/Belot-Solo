#include "../include/Utilities.h"

bool Utilities::bate(Culoare &atu, const Carte &a, const Carte &b, const Culoare &obl, Puncte &puncte) {
    const bool a_atu = a.getCuloare() == atu;
    const bool b_atu = b.getCuloare() == atu;
    if (a_atu && !b_atu)
        return true;
    if (!a_atu && b_atu)
        return false;
    if (a.getCuloare()==obl && b.getCuloare()==obl)
        return puncte.getPct()->at(a) > puncte.getPct()->at(b);
    if (a.getCuloare()==obl)
        return true;
    else return false;
}
