#include "../include/Carte.h"

Carte::Carte(const Culoare cul, const Rank ran): culoare(cul), rank(ran){};

Carte::Carte() {
    culoare = Culoare();
    rank = Rank();
}

Culoare Carte::getCuloare() const {
    return culoare;
}

Rank Carte::getRank() const {
    return rank;
}

std::ostream& operator<<(std::ostream& os, const Carte& carte) {
    switch (carte.rank) {
        case nine: os << "9"; break;
        case ten: os << "10"; break;
        case jack: os << "J"; break;
        case queen: os << "Q"; break;
        case king: os << "K"; break;
        case ace: os << "A"; break;
        default: os << "0"; break;
    }
    switch (carte.culoare) {
        case pica: os << "♠"; break;
        case trefla: os << "♣"; break;
        case diamant: os << "♦"; break;
        case inima: os << "♥"; break;
        default: os << "0"; break;
    }
    return os;
}

bool Carte::operator==(const Carte &carte) const {
    return culoare == carte.culoare && rank == carte.rank;
}

bool Carte::operator>(const Carte &carte) const {
    if (rank > carte.rank) {
        return true;
    } else if (rank == carte.rank) {
        return culoare > carte.culoare;
    } else
        return false;
}

bool Carte::operator<(const Carte &carte) const {
    if (rank < carte.rank) {
        return true;
    } else if (rank == carte.rank) {
        return culoare < carte.culoare;
    } else
        return false;
}




